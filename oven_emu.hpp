#ifndef __OVEN_EMU_HPP__
#define __OVEN_EMU_HPP__

#include <stdint.h>
#include <stdint.h>

#define VECTOR_SIZE 20
#define MODES        3
#define TEMP_OFFSET 15

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
   uint8_t read_temp();
   void on();
   void off();
   uint8_t getTarget(ctrl_modes_t mode, uint8_t period);

   private:
   uint8_t target_temp[MODES][VECTOR_SIZE];

   // variables to emulate the following of the temp by oven
   unsigned last_period;
   uint8_t period_fraction;
   unsigned last_mode;

};


#endif /* __OVEN_EMU_HPP__ */
