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
   // this is done every minute
   control();
   signals(bool *on, bool *off, bool *slow, bool *normal, bool *fast);
   // this is done every second
   check_signals();


   private:
   // this is the oven modeled
   oven_emu_t model;
   unsigned target_temp_array[TARGET_TMPS];
   unsigned time_counter;
   unsigned period;

   bool *on;

   bool mode;

   bool *slow;
   bool *normal;
   bool *fast;

};



#endif /* __OVEN_CONTROL_HPP__ */
