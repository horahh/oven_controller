
oven_control::oven_control()
{
   time_counter = 0;
   mode = OFF;
   period = 0;

}
oven_control::control(unsigned temp)
{
   if( OFF == mode )
   {
      return;
   }

   // read target temp from rom
   target_temp=model.getTarget(mode,period);

   //read temperature from oven
   temp = model.read_temp();
   // take control decisicion
   if( temp < target_temp )
   {
      model.on();
   }
   else
   {
      model.off();
   }
   // this should be incremented every minute when this
   // function gets called
   time_counter++;

   // every 5 minutes the period increases

   if( INTERVAL_TIME == time_counter )
   {
      time_counter = 0;
      period  = (period > 12 ) ? period : period++;
   }
   return;
}

oven_control::check_signals()
{

   if( true == on )
   {
      // if the device is on it wont change its behaviour
      return;
   }
   on = true;
   if( slow == true )
   {
      mode = SLOW;
   }
   else if( normal == true )
   {
      mode = NORMAL;
   }
   else if( fast == true )
   {
      mode = FAST;
   }
   else
   {
      mode = SLOW;
   }

}

oven_control::set_off()
{
   on = false;
   slow = false;
   normal = false;
   fast = false;
   model.off();
}

oven_control::set_slow()
{
   slow = true;
}
oven_control::set_normal()
{
   normal = true;
}
oven_control::set_fast()
{
   normal = true;
}
