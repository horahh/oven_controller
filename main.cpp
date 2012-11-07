
#include <stdio.h>
#include <time.h>
#include "oven_emu.hpp"
#include "oven_control.hpp"

#define TIME_UNIT     1
#define CONTROL_TIME 60


int main(int argc, int **argv)
{
   oven_control_t oven_control;
   oven_emu_t oven_emu;
   unsigned temp = 0;
   unsigned counter = 0;

   bool on;
   bool off;
   bool slow;
   bool normal;
   bool fast;

   // stablishing initial conditions
   on = true;
   off = false;
   slow = true;
   normal = true;

   // tell the controller where the signals to watch are
   oven_control.signals(&on, &off, &slow, &normal, &fast);

   while(true)
   { 
      counter ++;
      oven_control.check_signals();
      sleep(TIME_UNIT);
      if( CONTROL_TIME == counter )
      {
         // this will refresh oven temp lecture once every 5 minutes
         // This is the recalculation of the oven control signal
         oven_control.control();
         counter = 0;
      }


   }


}
