#ifndef _ROS_quadrotor_msgs_PolynomialTrajectory_h
#define _ROS_quadrotor_msgs_PolynomialTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/time.h"

namespace quadrotor_msgs
{

  class PolynomialTrajectory : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _trajectory_id_type;
      _trajectory_id_type trajectory_id;
      typedef uint32_t _type_type;
      _type_type type;
      typedef uint32_t _piece_num_yaw_type;
      _piece_num_yaw_type piece_num_yaw;
      typedef uint32_t _piece_num_pos_type;
      _piece_num_pos_type piece_num_pos;
      typedef uint32_t _order_pos_type;
      _order_pos_type order_pos;
      typedef uint32_t _order_yaw_type;
      _order_yaw_type order_yaw;
      typedef ros::Time _start_WT_yaw_type;
      _start_WT_yaw_type start_WT_yaw;
      typedef float _yaw_type;
      _yaw_type yaw;
      typedef float _yaw_rate_type;
      _yaw_rate_type yaw_rate;
      uint32_t coef_yaw_length;
      typedef float _coef_yaw_type;
      _coef_yaw_type st_coef_yaw;
      _coef_yaw_type * coef_yaw;
      uint32_t time_yaw_length;
      typedef float _time_yaw_type;
      _time_yaw_type st_time_yaw;
      _time_yaw_type * time_yaw;
      typedef ros::Time _start_WT_pos_type;
      _start_WT_pos_type start_WT_pos;
      uint32_t coef_pos_x_length;
      typedef float _coef_pos_x_type;
      _coef_pos_x_type st_coef_pos_x;
      _coef_pos_x_type * coef_pos_x;
      uint32_t coef_pos_y_length;
      typedef float _coef_pos_y_type;
      _coef_pos_y_type st_coef_pos_y;
      _coef_pos_y_type * coef_pos_y;
      uint32_t coef_pos_z_length;
      typedef float _coef_pos_z_type;
      _coef_pos_z_type st_coef_pos_z;
      _coef_pos_z_type * coef_pos_z;
      uint32_t time_pos_length;
      typedef float _time_pos_type;
      _time_pos_type st_time_pos;
      _time_pos_type * time_pos;
      typedef const char* _debug_info_type;
      _debug_info_type debug_info;
      enum { HEART_BEAT =    1     };
      enum { POSITION_TRAJ =    2     };
      enum { YAW_TRAJ =    4     };
      enum { YAW_COMMAND =    8     };
      enum { EMER_STOP =    16    };

    PolynomialTrajectory():
      header(),
      trajectory_id(0),
      type(0),
      piece_num_yaw(0),
      piece_num_pos(0),
      order_pos(0),
      order_yaw(0),
      start_WT_yaw(),
      yaw(0),
      yaw_rate(0),
      coef_yaw_length(0), st_coef_yaw(), coef_yaw(nullptr),
      time_yaw_length(0), st_time_yaw(), time_yaw(nullptr),
      start_WT_pos(),
      coef_pos_x_length(0), st_coef_pos_x(), coef_pos_x(nullptr),
      coef_pos_y_length(0), st_coef_pos_y(), coef_pos_y(nullptr),
      coef_pos_z_length(0), st_coef_pos_z(), coef_pos_z(nullptr),
      time_pos_length(0), st_time_pos(), time_pos(nullptr),
      debug_info("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->trajectory_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_id);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->piece_num_yaw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->piece_num_yaw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->piece_num_yaw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->piece_num_yaw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->piece_num_yaw);
      *(outbuffer + offset + 0) = (this->piece_num_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->piece_num_pos >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->piece_num_pos >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->piece_num_pos >> (8 * 3)) & 0xFF;
      offset += sizeof(this->piece_num_pos);
      *(outbuffer + offset + 0) = (this->order_pos >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->order_pos >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->order_pos >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->order_pos >> (8 * 3)) & 0xFF;
      offset += sizeof(this->order_pos);
      *(outbuffer + offset + 0) = (this->order_yaw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->order_yaw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->order_yaw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->order_yaw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->order_yaw);
      *(outbuffer + offset + 0) = (this->start_WT_yaw.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_WT_yaw.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_WT_yaw.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_WT_yaw.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_WT_yaw.sec);
      *(outbuffer + offset + 0) = (this->start_WT_yaw.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_WT_yaw.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_WT_yaw.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_WT_yaw.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_WT_yaw.nsec);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->yaw_rate);
      *(outbuffer + offset + 0) = (this->coef_yaw_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coef_yaw_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coef_yaw_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coef_yaw_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coef_yaw_length);
      for( uint32_t i = 0; i < coef_yaw_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coef_yaw[i]);
      }
      *(outbuffer + offset + 0) = (this->time_yaw_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_yaw_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_yaw_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_yaw_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_yaw_length);
      for( uint32_t i = 0; i < time_yaw_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->time_yaw[i]);
      }
      *(outbuffer + offset + 0) = (this->start_WT_pos.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_WT_pos.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_WT_pos.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_WT_pos.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_WT_pos.sec);
      *(outbuffer + offset + 0) = (this->start_WT_pos.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->start_WT_pos.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->start_WT_pos.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->start_WT_pos.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->start_WT_pos.nsec);
      *(outbuffer + offset + 0) = (this->coef_pos_x_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coef_pos_x_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coef_pos_x_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coef_pos_x_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coef_pos_x_length);
      for( uint32_t i = 0; i < coef_pos_x_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coef_pos_x[i]);
      }
      *(outbuffer + offset + 0) = (this->coef_pos_y_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coef_pos_y_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coef_pos_y_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coef_pos_y_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coef_pos_y_length);
      for( uint32_t i = 0; i < coef_pos_y_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coef_pos_y[i]);
      }
      *(outbuffer + offset + 0) = (this->coef_pos_z_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->coef_pos_z_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->coef_pos_z_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->coef_pos_z_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coef_pos_z_length);
      for( uint32_t i = 0; i < coef_pos_z_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->coef_pos_z[i]);
      }
      *(outbuffer + offset + 0) = (this->time_pos_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_pos_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_pos_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_pos_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_pos_length);
      for( uint32_t i = 0; i < time_pos_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->time_pos[i]);
      }
      uint32_t length_debug_info = strlen(this->debug_info);
      varToArr(outbuffer + offset, length_debug_info);
      offset += 4;
      memcpy(outbuffer + offset, this->debug_info, length_debug_info);
      offset += length_debug_info;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->trajectory_id =  ((uint32_t) (*(inbuffer + offset)));
      this->trajectory_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->trajectory_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->trajectory_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->trajectory_id);
      this->type =  ((uint32_t) (*(inbuffer + offset)));
      this->type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type);
      this->piece_num_yaw =  ((uint32_t) (*(inbuffer + offset)));
      this->piece_num_yaw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->piece_num_yaw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->piece_num_yaw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->piece_num_yaw);
      this->piece_num_pos =  ((uint32_t) (*(inbuffer + offset)));
      this->piece_num_pos |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->piece_num_pos |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->piece_num_pos |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->piece_num_pos);
      this->order_pos =  ((uint32_t) (*(inbuffer + offset)));
      this->order_pos |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->order_pos |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->order_pos |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->order_pos);
      this->order_yaw =  ((uint32_t) (*(inbuffer + offset)));
      this->order_yaw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->order_yaw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->order_yaw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->order_yaw);
      this->start_WT_yaw.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_WT_yaw.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_WT_yaw.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_WT_yaw.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_WT_yaw.sec);
      this->start_WT_yaw.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_WT_yaw.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_WT_yaw.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_WT_yaw.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_WT_yaw.nsec);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->yaw_rate));
      uint32_t coef_yaw_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coef_yaw_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coef_yaw_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coef_yaw_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coef_yaw_length);
      if(coef_yaw_lengthT > coef_yaw_length)
        this->coef_yaw = (float*)realloc(this->coef_yaw, coef_yaw_lengthT * sizeof(float));
      coef_yaw_length = coef_yaw_lengthT;
      for( uint32_t i = 0; i < coef_yaw_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coef_yaw));
        memcpy( &(this->coef_yaw[i]), &(this->st_coef_yaw), sizeof(float));
      }
      uint32_t time_yaw_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_yaw_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_yaw_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_yaw_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_yaw_length);
      if(time_yaw_lengthT > time_yaw_length)
        this->time_yaw = (float*)realloc(this->time_yaw, time_yaw_lengthT * sizeof(float));
      time_yaw_length = time_yaw_lengthT;
      for( uint32_t i = 0; i < time_yaw_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_time_yaw));
        memcpy( &(this->time_yaw[i]), &(this->st_time_yaw), sizeof(float));
      }
      this->start_WT_pos.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_WT_pos.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_WT_pos.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_WT_pos.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_WT_pos.sec);
      this->start_WT_pos.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->start_WT_pos.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->start_WT_pos.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->start_WT_pos.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->start_WT_pos.nsec);
      uint32_t coef_pos_x_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coef_pos_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coef_pos_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coef_pos_x_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coef_pos_x_length);
      if(coef_pos_x_lengthT > coef_pos_x_length)
        this->coef_pos_x = (float*)realloc(this->coef_pos_x, coef_pos_x_lengthT * sizeof(float));
      coef_pos_x_length = coef_pos_x_lengthT;
      for( uint32_t i = 0; i < coef_pos_x_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coef_pos_x));
        memcpy( &(this->coef_pos_x[i]), &(this->st_coef_pos_x), sizeof(float));
      }
      uint32_t coef_pos_y_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coef_pos_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coef_pos_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coef_pos_y_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coef_pos_y_length);
      if(coef_pos_y_lengthT > coef_pos_y_length)
        this->coef_pos_y = (float*)realloc(this->coef_pos_y, coef_pos_y_lengthT * sizeof(float));
      coef_pos_y_length = coef_pos_y_lengthT;
      for( uint32_t i = 0; i < coef_pos_y_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coef_pos_y));
        memcpy( &(this->coef_pos_y[i]), &(this->st_coef_pos_y), sizeof(float));
      }
      uint32_t coef_pos_z_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      coef_pos_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      coef_pos_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      coef_pos_z_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->coef_pos_z_length);
      if(coef_pos_z_lengthT > coef_pos_z_length)
        this->coef_pos_z = (float*)realloc(this->coef_pos_z, coef_pos_z_lengthT * sizeof(float));
      coef_pos_z_length = coef_pos_z_lengthT;
      for( uint32_t i = 0; i < coef_pos_z_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_coef_pos_z));
        memcpy( &(this->coef_pos_z[i]), &(this->st_coef_pos_z), sizeof(float));
      }
      uint32_t time_pos_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_pos_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_pos_length);
      if(time_pos_lengthT > time_pos_length)
        this->time_pos = (float*)realloc(this->time_pos, time_pos_lengthT * sizeof(float));
      time_pos_length = time_pos_lengthT;
      for( uint32_t i = 0; i < time_pos_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_time_pos));
        memcpy( &(this->time_pos[i]), &(this->st_time_pos), sizeof(float));
      }
      uint32_t length_debug_info;
      arrToVar(length_debug_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_debug_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_debug_info-1]=0;
      this->debug_info = (char *)(inbuffer + offset-1);
      offset += length_debug_info;
     return offset;
    }

    virtual const char * getType() override { return "quadrotor_msgs/PolynomialTrajectory"; };
    virtual const char * getMD5() override { return "e47033bc2f3299c439cff56cedbdf3f4"; };

  };

}
#endif
