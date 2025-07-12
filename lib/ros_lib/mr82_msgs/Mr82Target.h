#ifndef _ROS_mr82_msgs_Mr82Target_h
#define _ROS_mr82_msgs_Mr82Target_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace mr82_msgs
{

  class Mr82Target : public ros::Msg
  {
    public:
      typedef float _angle_deg_type;
      _angle_deg_type angle_deg;
      typedef float _speed_mps_type;
      _speed_mps_type speed_mps;
      typedef float _distance_m_type;
      _distance_m_type distance_m;
      typedef uint8_t _id_type;
      _id_type id;

    Mr82Target():
      angle_deg(0),
      speed_mps(0),
      distance_m(0),
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle_deg;
      u_angle_deg.real = this->angle_deg;
      *(outbuffer + offset + 0) = (u_angle_deg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_deg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_deg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_deg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_deg);
      union {
        float real;
        uint32_t base;
      } u_speed_mps;
      u_speed_mps.real = this->speed_mps;
      *(outbuffer + offset + 0) = (u_speed_mps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed_mps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed_mps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed_mps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed_mps);
      union {
        float real;
        uint32_t base;
      } u_distance_m;
      u_distance_m.real = this->distance_m;
      *(outbuffer + offset + 0) = (u_distance_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance_m);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle_deg;
      u_angle_deg.base = 0;
      u_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_deg = u_angle_deg.real;
      offset += sizeof(this->angle_deg);
      union {
        float real;
        uint32_t base;
      } u_speed_mps;
      u_speed_mps.base = 0;
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed_mps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed_mps = u_speed_mps.real;
      offset += sizeof(this->speed_mps);
      union {
        float real;
        uint32_t base;
      } u_distance_m;
      u_distance_m.base = 0;
      u_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance_m = u_distance_m.real;
      offset += sizeof(this->distance_m);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
     return offset;
    }

    virtual const char * getType() override { return "mr82_msgs/Mr82Target"; };
    virtual const char * getMD5() override { return "90dc19b47b437eb991e808ea5f3fc439"; };

  };

}
#endif
