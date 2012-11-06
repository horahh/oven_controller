
oven_control::oven_control()
{
   time_counter = 0;

   target_temp_array[0] = 0;
   target_temp_array[1] = 1;


}
oven_control::control(unsigned temp)
{
   unsigned target_temp=0;
   //read temperature from oven
   temp = model.read_temp();
   // calculate target temp
   target_temp = target_temp_array[time_counter/INTERVAL_TIME]
   // take control decisicion
   if( temp < target_temp )
   {
      model.on();
   }
   else
   {
      model.off();
   }
}
