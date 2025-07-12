#ifndef _ROS_quadrotor_msgs_MpcPositionCommand_h
#define _ROS_quadrotor_msgs_MpcPositionCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "quadrotor_msgs/PositionCommand.h"

namespace quadrotor_msgs
{

  class MpcPositionCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t cmds_length;
      typedef quadrotor_msgs::PositionCommand _cmds_type;
      _cmds_type st_cmds;
      _cmds_type * cmds;
      typedef uint32_t _mpc_horizon_type;
      _mpc_horizon_type mpc_horizon;
      typedef uint8_t _command_flag_type;
      _command_flag_type command_flag;
      enum { NORMAL_COMMAND =  1 };
      enum { BLOCK_COMMAND =  137 };

    MpcPositionCommand():
      header(),
      cmds_length(0), st_cmds(), cmds(nullptr),
      mpc_horizon(0),
      command_flag(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->cmds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cmds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cmds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cmds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmds_length);
      for( uint32_t i = 0; i < cmds_length; i++){
      offset += this->cmds[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->mpc_horizon >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mpc_horizon >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mpc_horizon >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mpc_horizon >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mpc_horizon);
      *(outbuffer + offset + 0) = (this->command_flag >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command_flag);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t cmds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cmds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cmds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cmds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cmds_length);
      if(cmds_lengthT > cmds_length)
        this->cmds = (quadrotor_msgs::PositionCommand*)realloc(this->cmds, cmds_lengthT * sizeof(quadrotor_msgs::PositionCommand));
      cmds_length = cmds_lengthT;
      for( uint32_t i = 0; i < cmds_length; i++){
      offset += this->st_cmds.deserialize(inbuffer + offset);
        memcpy( &(this->cmds[i]), &(this->st_cmds), sizeof(quadrotor_msgs::PositionCommand));
      }
      this->mpc_horizon =  ((uint32_t) (*(inbuffer + offset)));
      this->mpc_horizon |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->mpc_horizon |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->mpc_horizon |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->mpc_horizon);
      this->command_flag =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command_flag);
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/MpcPositionCommand"; };
    virtual const char * getMD5() override { return "d5da74eb84dd86c3c380b221a8a0b6ae"; };

  };

}
#endif
