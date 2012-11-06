#ifndef __OVEN_EMU_HPP__
#define __OVEN_EMU_HPP__

#define VECTOR_SIZE 20

class oven_emu
{
   public:
   oven_emu();
   read_temp();
   on();
   off();

   private:
   unsigned time_count;
   unsigned response[VECTOR_SIZE];
};



#endif /* __OVEN_EMU_HPP__ */
