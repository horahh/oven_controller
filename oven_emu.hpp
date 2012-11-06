
oven_emu::oven_emu()
{
   time_count = 0;


   response[0] = 0;
   response[1] = 1;


}

oven_emu::read_temp()
{
   return response[time_count];

}

void oven_emu::on()
{
   time_count++;
}
void oven_emu::off()
{
}
