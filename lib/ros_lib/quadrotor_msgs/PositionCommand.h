#ifndef _ROS_quadrotor_msgs_PositionCommand_h
#define _ROS_quadrotor_msgs_PositionCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace quadrotor_msgs
{

  class PositionCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Vector3 _jerk_type;
      _jerk_type jerk;
      typedef geometry_msgs::Vector3 _angular_velocity_type;
      _angular_velocity_type angular_velocity;
      typedef geometry_msgs::Vector3 _attitude_type;
      _attitude_type attitude;
      typedef geometry_msgs::Vector3 _thrust_type;
      _thrust_type thrust;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _yaw_dot_type;
      _yaw_dot_type yaw_dot;
      typedef float _vel_norm_type;
      _vel_norm_type vel_norm;
      typedef float _acc_norm_type;
      _acc_norm_type acc_norm;
      float kx[3];
      float kv[3];
      typedef uint32_t _trajectory_id_type;
      _trajectory_id_type trajectory_id;
      typedef uint8_t _trajectory_flag_type;
      _trajectory_flag_type trajectory_flag;
      enum { TRAJECTORY_STATUS_EMPTY =  0 };
      enum { TRAJECTORY_STATUS_EMER =  2 };
      enum { TRAJECTORY_STATUS_READY =  1 };
      enum { TRAJECTORY_STATUS_COMPLETED =  3 };
      enum { TRAJECTROY_STATUS_ABORT =  4 };
      enum { TRAJECTORY_STATUS_ILLEGAL_START =  5 };
      enum { TRAJECTORY_STATUS_ILLEGAL_FINAL =  6 };
      enum { TRAJECTORY_STATUS_IMPOSSIBLE =  7 };
      enum { ACTION_STOP =    8 };

    PositionCommand():
      header(),
      position(),
      velocity(),
      acceleration(),
      jerk(),
      angular_velocity(),
      attitude(),
      thrust(),
      yaw(0),
      yaw_dot(0),
      vel_norm(0),
      acc_norm(0),
      kx(),
      kv(),
      trajectory_id(0),
      trajectory_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->jerk.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      offset += this->attitude.serialize(outbuffer + offset);
      offset += this->thrust.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw_dot);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel_norm);
      offset += serializeAvrFloat64(outbuffer + offset, this->acc_norm);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->kx[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->kv[i]);
      }
      *(outbuffer + offset + 0) = (this->trajectory_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_id);
      *(outbuffer + offset + 0) = (this->trajectory_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trajectory_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->jerk.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      offset += this->attitude.deserialize(inbuffer + offset);
      offset += this->thrust.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw_dot));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel_norm));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acc_norm));
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kx[i]));
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->kv[i]));
      }
      this->trajectory_id =  ((uint32_t) (*(inbuffer + offset)));
      this->trajectory_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trajectory_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trajectory_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trajectory_id);
      this->trajectory_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->trajectory_flag);
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/PositionCommand"; };
    virtual const char * getMD5() override { return "d008e86de36e11deb1e4033ac2c394a9"; };

  };

}
#endif
