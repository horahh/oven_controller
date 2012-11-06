#ifndef __OVEN_CONTROL_HPP__
#define __OVEN_CONTROL_HPP__

#include "oven_emu.hpp"

#define TARGET_TMPS 10 
// number of samples in each single target temperature interval
// as it is 5 minutes and 1 minute samples result is 5
#define INTERVAL_TIME 5 

class oven_control
{
   public:
   control();

   private:
   // this is the oven modeled
   oven_emu_t model;
   unsigned target_temp_array[TARGET_TMPS];
   unsigned time_counter;

};



#endif /* __OVEN_CONTROL_HPP__ */
