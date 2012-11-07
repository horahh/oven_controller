
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "oven_emu.hpp"
#include "oven_control.hpp"

#define TIME_UNIT     1
#define CONTROL_TIME 60

// signals
bool on;
bool off;
bool slow;
bool normal;
bool fast;

int main(int argc, char **argv)
{
   oven_control oven_control;
   unsigned counter = 0;


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
      usleep(TIME_UNIT);
      if( CONTROL_TIME == counter )
      {
         // this will refresh oven temp lecture once every 5 minutes
         // This is the recalculation of the oven control signal
         oven_control.control();
         counter = 0;
      }


   }


}
