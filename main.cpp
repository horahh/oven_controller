
#include <time.h>
#include "oven_emu.hpp"
#include "oven_control.hpp"

#define TIME_UNIT 60



int main(int argc, int **argv)
{
   int counter = 0;
   oven_control_t oven_control;
   oven_emu_t oven_emu;
   unsigned temp=0;

   while(true)
   { 
      sleep(TIME_UNIT);
      counter ++;
      if( 5 == counter )
      {
         // this will refresh oven temp lecture once every 5 minutes
         oven_emu.refresh_temp();
         counter = 0;
      }
      oven_control.control();

   }


}
