#include "oven_emu.hpp"

oven_emu::oven_emu()
{
   last_period = 0;
   period_fraction = 0;
   last_mode = OFF;


   // slow mode target_temp
   target_temp[0][ 0] = 17  + TEMP_OFFSET;
   target_temp[0][ 1] = 25  + TEMP_OFFSET;
   target_temp[0][ 2] = 35  + TEMP_OFFSET;
   target_temp[0][ 3] = 50  + TEMP_OFFSET;
   target_temp[0][ 4] = 60  + TEMP_OFFSET;
   target_temp[0][ 5] = 80  + TEMP_OFFSET;
   target_temp[0][ 6] = 105 + TEMP_OFFSET;
   target_temp[0][ 7] = 100 + TEMP_OFFSET;
   target_temp[0][ 8] = 80  + TEMP_OFFSET;
   target_temp[0][ 9] = 70  + TEMP_OFFSET;
   target_temp[0][10] = 70  + TEMP_OFFSET;
   target_temp[0][11] = 70  + TEMP_OFFSET;
   target_temp[0][12] = 70  + TEMP_OFFSET;


   // normal mode target_temp
   target_temp[1][ 0] = 18  + TEMP_OFFSET;
   target_temp[1][ 1] = 40  + TEMP_OFFSET;
   target_temp[1][ 2] = 55  + TEMP_OFFSET;
   target_temp[1][ 3] = 75  + TEMP_OFFSET;
   target_temp[1][ 4] = 80  + TEMP_OFFSET;
   target_temp[1][ 5] = 95  + TEMP_OFFSET;
   target_temp[1][ 6] = 115 + TEMP_OFFSET;
   target_temp[1][ 7] = 110 + TEMP_OFFSET;
   target_temp[1][ 8] = 100 + TEMP_OFFSET;
   target_temp[1][ 9] = 80  + TEMP_OFFSET;
   target_temp[1][10] = 75  + TEMP_OFFSET;
   target_temp[1][11] = 70  + TEMP_OFFSET;
   target_temp[1][12] = 70  + TEMP_OFFSET;

   // fast mode target_temp 
   target_temp[2][ 0] = 20  + TEMP_OFFSET;
   target_temp[2][ 1] = 50  + TEMP_OFFSET;
   target_temp[2][ 2] = 70  + TEMP_OFFSET;
   target_temp[2][ 3] = 90  + TEMP_OFFSET;
   target_temp[2][ 4] = 110 + TEMP_OFFSET;
   target_temp[2][ 5] = 90  + TEMP_OFFSET;
   target_temp[2][ 6] = 80  + TEMP_OFFSET;
   target_temp[2][ 7] = 75  + TEMP_OFFSET;
   target_temp[2][ 8] = 70  + TEMP_OFFSET;
   target_temp[2][ 9] = 70  + TEMP_OFFSET;
   target_temp[2][10] = 70  + TEMP_OFFSET;
   target_temp[2][11] = 70  + TEMP_OFFSET;
   target_temp[2][12] = 70  + TEMP_OFFSET;
}
uint8_t oven_emu::getTarget(ctrl_modes_t mode, unsigned period)
{
   last_period = period;
   period_fraction = 0;
   last_mode = mode;
   return target_temp[mode][period];
}

uint8_t oven_emu::read_temp()
{
   uint8_t target_temp_current = target_temp[last_mode][last_period];
   uint8_t ini_temp; 
   uint8_t emulated_temp;

   if( last_period != 0 )
   {
      ini_temp = target_temp[last_mode][last_period-1];
   }
   else
   {
      ini_temp = 0;
   }

   if( period_fraction < 5 )
   {
      emulated_temp = ini_temp + period_fraction / 5 * (target_temp_current - ini_temp);
   }
   else
   {
      emulated_temp = target_temp_current;
   }
   period_fraction++;
   
   return emulated_temp;
}

void oven_emu::on()
{
   period_fraction++;
}
void oven_emu::off()
{
   period_fraction = 0;
   last_period = 0;
   last_mode = OFF;
}



