# MR82毫米波雷达ROS节点接入示例（ESP32+rosserial）
本项目演示如何使用ESP32读取MR82毫米波雷达的串口，解析雷达目标信息（ID，距离，速度和角度），并通过rosserial发送ROS节点。

## 项目功能
——   通过UART2接收MR82毫米波雷达输出数据（通过比较只输出距离最近目标）
——  实时解析雷达目标帧
——  使用卡尔曼滤波平滑距离、速度、角度信息
——  选择“距离最近的目标”作为发布对象
——  通过rosserial向ROS发布目标信息（话题名称：uav_radar）

## 消息格式说明（mr82_msgs/Mr82Target.h）
### msg如下：
uint8 id
float32 distance_m
float32 angle_deg
float32 speed_mps