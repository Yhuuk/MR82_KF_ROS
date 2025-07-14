#include <Arduino.h>
#include <ros.h>
#include <mr82_msgs/Mr82Target.h>

#define RXD2 16
#define TXD2 17
#define MAX_TARGETS 8
#define FRAME_SIZE 14

// ROS 初始化
ros::NodeHandle nh;
mr82_msgs::Mr82Target target;
ros::Publisher pub("uav_radar", &target);

// 卡尔曼滤波器
class KalmanFliter {
public:
  KalmanFliter(float q = 0.05, float r = 1.0) {
    Q = q; R = r;
    P = 1.0;
    X = 0.0;
    initialized = false;
  }

  float Update(float measure) {
    if (!initialized) {
      X = measure;
      initialized = true;
    }
    P = P + Q;
    float K = P / (P + R);
    X = X + K * (measure - X);
    P = (1 - K) * P;
    return X;
  }

private:
  float Q, R, P, X;
  bool initialized;
};

KalmanFliter dis_KF(0.1, 1.0);
KalmanFliter speed_KF(0.1, 1.0);
KalmanFliter angle_KF(0.1, 1.0);

// 目标帧缓存结构
struct RadarTarget {
  uint8_t raw[FRAME_SIZE];
  float distance;
};

// 最多缓存8个目标
RadarTarget targets[MAX_TARGETS];
int target_count = 0;

// 解析一帧雷达数据
bool parseTarget(uint8_t* buffer, mr82_msgs::Mr82Target* msg_out) {
  if (buffer[0] != 0xAA || buffer[1] != 0xAA ||
      buffer[2] != 0x0C || buffer[3] != 0x07 ||
      buffer[12] != 0x55 || buffer[13] != 0x55) {
    return false;
  }

  msg_out->id = buffer[4];

  uint16_t range_raw   = (buffer[6] << 8) | buffer[7];
  uint16_t azimuth_raw = (buffer[5] << 8) | buffer[8];
  uint16_t vrel_raw    = ((buffer[9] & 0x07) << 8) | buffer[10];

  float range   = range_raw * 0.01f;
  float azimuth = azimuth_raw * 0.01f - 90.0f;
  float vrel    = vrel_raw * 0.05f - 35.0f;

  msg_out->distance_m = dis_KF.Update(range);
  msg_out->angle_deg  = angle_KF.Update(azimuth);
  msg_out->speed_mps  = speed_KF.Update(vrel);

  return true;
}

void setup() {
  Serial.begin(460800);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  nh.getHardware()->setBaud(460800);
  nh.initNode();
  nh.advertise(pub);

  Serial.println("✅ MR82 雷达开始工作，等待数据...");
}

void loop() {
  static uint8_t buffer[FRAME_SIZE];
  static uint8_t idx = 0;
  target_count = 0;

  // 接收并缓存最多8个目标
  while (Serial2.available() && target_count < MAX_TARGETS) {
    buffer[idx++] = Serial2.read();

    if (idx >= FRAME_SIZE) {
      if (buffer[0] == 0xAA && buffer[1] == 0xAA &&
          buffer[2] == 0x0C && buffer[3] == 0x07 &&
          buffer[12] == 0x55 && buffer[13] == 0x55) {

        // 缓存当前目标帧
        memcpy(targets[target_count].raw, buffer, FRAME_SIZE);

        // 提取原始距离（不加滤波）用于排序
        uint16_t range_raw = (buffer[6] << 8) | buffer[7];
        targets[target_count].distance = range_raw * 0.01f;
        target_count++;
      }

      // 滑动窗口读取下一帧
      memmove(buffer, buffer + 1, FRAME_SIZE - 1);
      idx = FRAME_SIZE - 1;
    }
  }

  // 发布最近目标
  if (target_count > 0) {
    int min_index = 0;
    for (int i = 1; i < target_count; ++i) {
      if (targets[i].distance < targets[min_index].distance) {
        min_index = i;
      }
    }

    // 解析并发布最近目标
    if (parseTarget(targets[min_index].raw, &target)) {
      pub.publish(&target);
    }
  }

  nh.spinOnce();
  delay(10);
}
