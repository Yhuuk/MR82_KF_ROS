#ifndef _ROS_quadrotor_msgs_QuadrotorState_h
#define _ROS_quadrotor_msgs_QuadrotorState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/Vector3.h"

namespace quadrotor_msgs
{

  class QuadrotorState : public ros::Msg
  {
    public:
      typedef float _thrust_type;
      _thrust_type thrust;
      typedef float _velocity_norm_type;
      _velocity_norm_type velocity_norm;
      typedef float _acceleration_norm_type;
      _acceleration_norm_type acceleration_norm;
      typedef float _jerk_norm_type;
      _jerk_norm_type jerk_norm;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef geometry_msgs::Vector3 _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef geometry_msgs::Vector3 _jerk_type;
      _jerk_type jerk;
      typedef geometry_msgs::Vector3 _snap_type;
      _snap_type snap;
      typedef geometry_msgs::Vector3 _attitude_type;
      _attitude_type attitude;
      typedef geometry_msgs::Vector3 _angular_velocity_type;
      _angular_velocity_type angular_velocity;

    QuadrotorState():
      thrust(0),
      velocity_norm(0),
      acceleration_norm(0),
      jerk_norm(0),
      position(),
      velocity(),
      acceleration(),
      jerk(),
      snap(),
      attitude(),
      angular_velocity()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->thrust);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_norm);
      offset += serializeAvrFloat64(outbuffer + offset, this->acceleration_norm);
      offset += serializeAvrFloat64(outbuffer + offset, this->jerk_norm);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      offset += this->jerk.serialize(outbuffer + offset);
      offset += this->snap.serialize(outbuffer + offset);
      offset += this->attitude.serialize(outbuffer + offset);
      offset += this->angular_velocity.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->thrust));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity_norm));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->acceleration_norm));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->jerk_norm));
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      offset += this->jerk.deserialize(inbuffer + offset);
      offset += this->snap.deserialize(inbuffer + offset);
      offset += this->attitude.deserialize(inbuffer + offset);
      offset += this->angular_velocity.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/QuadrotorState"; };
    virtual const char * getMD5() override { return "9f6239376b083d84c39413d50a0b4367"; };

  };

}
#endif
