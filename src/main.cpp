#include <Arduino.h>
#include <ros.h>
#include <mr82_msgs/Mr82Target.h>

//UART2 for radar
#define RXD2 16
#define TXD2 17


class KalmanFliter
{
  public:
    KalmanFliter(float q = 0.05,float r = 1.0)
    {
        Q = q;
        R = r;
        P = 1.0;
        X = 0.0;
        initiallized = false;
    }

  float Update(float measure)
  {
    if(!initiallized)
    {
      X = measure;
      initiallized = true;
      
    }

      P = P + Q;           //更新预测
      float K = P/(P+R);         //计算增益
      X = X + K*(measure - X);
      P = (1-K)*P;         //再次更新预测值（根据K增益修正P）

      return X;
  }


  private:
  float  Q, R, P, X;
  bool initiallized;
};

//ROS中的初始化
ros::NodeHandle nh;   //ros中的大管家 
mr82_msgs::Mr82Target target;  //自定义消息类型
ros::Publisher pub("uav_radar",&target);  //发布话题

//卡尔曼滤波器（距离，速度，角度）
KalmanFliter dis_KF(0.1,1.0);
KalmanFliter speed_KF(0.1,1.0);
KalmanFliter angle_KF(0.1,1.0);


//解析MR82毫米波雷达的数据，并打包到ros的自定义包中
bool parseTarget(uint8_t* buffer, mr82_msgs::Mr82Target* msg)
{
  //判断雷达的数据包头包尾是否正确还有消息类型是否为目标输出信息
    if(buffer[0] != 0xAA || buffer[1] != 0xAA ||
       buffer[2] != 0x0C || buffer[3] != 0x07 ||
       buffer[12] != 0x55 || buffer[13] != 0x55
    ){
      return false;
    }

    msg->id = buffer[4];  //第5位为id号

    uint16_t Range_raw = (buffer[6] << 8) | buffer[7];
    uint16_t Azimuth_raw = (buffer[5] << 8) | buffer[8];
    uint16_t Vrel_raw = ((buffer[9] & 0x07) << 8) | buffer[10];

    float distance = Range_raw * 0.01f;
    float angle = Azimuth_raw * 0.01f - 90.0f;
    float speed = Vrel_raw * 0.05f -35.0f;

  msg ->distance_m = dis_KF.Update(distance);
  msg ->angle_deg = angle_KF.Update(angle);
  msg ->speed_mps = speed_KF.Update(speed);

  return true;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(460800);
  nh.getHardware()->setBaud(460800);  //设置与ROS主机通信的波特率

  
  nh.initNode();
  nh.advertise(pub);

  Serial2.begin(115200,SERIAL_8N1,RXD2,TXD2);
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t buffer[14];  //接受雷达信号
  static uint8_t idx = 0;     //帮助buffer计数

  while(Serial2.available())
  {
    buffer[idx++] = Serial2.read();
    if(idx >= 14)
    {
      if(parseTarget(buffer,&target))
      {
        pub.publish(&target);

      }
      memmove(buffer,buffer + 1, 13);
      idx = 13;

    }

  }
    nh.spinOnce();
    // delay(500);
}
