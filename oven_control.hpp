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
   oven_control();
   // this is done every minute
   void control();
   void signals(bool *on, bool *off, bool *slow, bool *normal, bool *fast);
   // this is done every second
   void check_signals();


   private:
   //functions
   void set_off();
   void set_slow();
   void set_normal();
   void set_fast();


   // this is the oven modeled
   oven_emu model;
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
