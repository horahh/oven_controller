
oven_emu::oven_emu()
{
   period_interval = 0;

   // slow mode response
   response[0][ 0] = 17  + TEMP_OFFSET;
   response[0][ 1] = 25  + TEMP_OFFSET;
   response[0][ 2] = 35  + TEMP_OFFSET;
   response[0][ 3] = 50  + TEMP_OFFSET;
   response[0][ 4] = 60  + TEMP_OFFSET;
   response[0][ 5] = 80  + TEMP_OFFSET;
   response[0][ 6] = 105 + TEMP_OFFSET;
   response[0][ 7] = 100 + TEMP_OFFSET;
   response[0][ 8] = 80  + TEMP_OFFSET;
   response[0][ 9] = 70  + TEMP_OFFSET;
   response[0][10] = 70  + TEMP_OFFSET;
   response[0][11] = 70  + TEMP_OFFSET;
   response[0][12] = 70  + TEMP_OFFSET;


   // normal mode response
   response[1][ 0] = 18  + TEMP_OFFSET;
   response[1][ 1] = 40  + TEMP_OFFSET;
   response[1][ 2] = 55  + TEMP_OFFSET;
   response[1][ 3] = 75  + TEMP_OFFSET;
   response[1][ 4] = 80  + TEMP_OFFSET;
   response[1][ 5] = 95  + TEMP_OFFSET;
   response[1][ 6] = 115 + TEMP_OFFSET;
   response[1][ 7] = 110 + TEMP_OFFSET;
   response[1][ 8] = 100 + TEMP_OFFSET;
   response[1][ 9] = 80  + TEMP_OFFSET;
   response[1][10] = 75  + TEMP_OFFSET;
   response[1][11] = 70  + TEMP_OFFSET;
   response[1][12] = 70  + TEMP_OFFSET;

   // fast mode response 
   response[2][ 0] = 20  + TEMP_OFFSET;
   response[2][ 1] = 50  + TEMP_OFFSET;
   response[2][ 2] = 70  + TEMP_OFFSET;
   response[2][ 3] = 90  + TEMP_OFFSET;
   response[2][ 4] = 110 + TEMP_OFFSET;
   response[2][ 5] = 90  + TEMP_OFFSET;
   response[2][ 6] = 80  + TEMP_OFFSET;
   response[2][ 7] = 75  + TEMP_OFFSET;
   response[2][ 8] = 70  + TEMP_OFFSET;
   response[2][ 9] = 70  + TEMP_OFFSET;
   response[2][10] = 70  + TEMP_OFFSET;
   response[2][11] = 70  + TEMP_OFFSET;
   response[2][12] = 70  + TEMP_OFFSET;
}
uint8_t oven_emu::getTarget(ctrl_modes_t mode, unsigned period)
{
   last_period = period;
   period_interval = 0;
   last_mode = mode;
   return response[mode][period];
}

oven_emu::read_temp()
{
   uint8_t target_temp = response[last_mode][last_period];
   uint8_t ini_temp; 
   uint8_t emulated_temp;

   if( last_period == 0 )
   {
      begin_temp = response[last_mode][last_period-1];
   }
   else
   {
      begin_temp = 0;
   }

   if( period_interval < 5 )
   {
      emulated_temp = ini_temp + period_interval / 5.0 * (target_temp - ini_temp);
   }
   else
   {
      emulated_temp = target_temp;
   }
   period_interval++;
   
   return emulated_temp;
}

void oven_emu::on()
{
   period_interval++;
}
void oven_emu::off()
{
}



