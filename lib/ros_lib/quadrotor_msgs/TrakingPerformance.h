#ifndef _ROS_quadrotor_msgs_TrakingPerformance_h
#define _ROS_quadrotor_msgs_TrakingPerformance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/Int64.h"
#include "std_msgs/String.h"
#include "quadrotor_msgs/QuadrotorState.h"

namespace quadrotor_msgs
{

  class TrakingPerformance : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::Int64 _fsm_state_id_type;
      _fsm_state_id_type fsm_state_id;
      typedef std_msgs::String _fsm_state_type;
      _fsm_state_type fsm_state;
      typedef float _mpc_solve_time_type;
      _mpc_solve_time_type mpc_solve_time;
      typedef float _suggest_hover_percentage_type;
      _suggest_hover_percentage_type suggest_hover_percentage;
      typedef quadrotor_msgs::QuadrotorState _reference_type;
      _reference_type reference;
      typedef quadrotor_msgs::QuadrotorState _command_type;
      _command_type command;
      typedef quadrotor_msgs::QuadrotorState _feedback_type;
      _feedback_type feedback;
      typedef quadrotor_msgs::QuadrotorState _error_type;
      _error_type error;

    TrakingPerformance():
      header(),
      fsm_state_id(),
      fsm_state(),
      mpc_solve_time(0),
      suggest_hover_percentage(0),
      reference(),
      command(),
      feedback(),
      error()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->fsm_state_id.serialize(outbuffer + offset);
      offset += this->fsm_state.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->mpc_solve_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->suggest_hover_percentage);
      offset += this->reference.serialize(outbuffer + offset);
      offset += this->command.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      offset += this->error.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->fsm_state_id.deserialize(inbuffer + offset);
      offset += this->fsm_state.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mpc_solve_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->suggest_hover_percentage));
      offset += this->reference.deserialize(inbuffer + offset);
      offset += this->command.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
      offset += this->error.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/TrakingPerformance"; };
    virtual const char * getMD5() override { return "9f13f07f1cf4826fffc678464e2f5e1e"; };

  };

}
#endif
