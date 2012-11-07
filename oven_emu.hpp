#ifndef __OVEN_EMU_HPP__
#define __OVEN_EMU_HPP__

#define VECTOR_SIZE  20
#define MODES         3
#define TEMP_OFFSET -15

typedef enum ctrl_modes_e
{
   SLOW = 0,
   NORMAL,
   FAST,
   OFF
} ctrl_modes_t;
   

class oven_emu
{
   public:
   oven_emu();
   read_temp();
   on();
   off();
   uint8_t getTarget(ctrl_modes_t mode, unsigned period);

   private:
   uint8_t target_temp[MODES][VECTOR_SIZE];

   // variables to emulate the following of the temp by oven
   unsigned last_period;
   unsigned period_interval;

};


#endif /* __OVEN_EMU_HPP__ */
