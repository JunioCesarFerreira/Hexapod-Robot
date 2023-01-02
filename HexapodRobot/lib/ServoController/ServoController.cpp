#include "ServoController.h"

hw_timer_t *hw_timer = NULL;
uint16_t countTimer = 0;
uint16_t servo_boundery[SERVOS_AMOUNT];
int8_t servos[SERVOS_AMOUNT] =
{
   1, 2, 3, 
   4, 5, 6,
   7, 8, 9,
  10, 11, 12,
  13, 14, -1,
  -1, -1, -1
};

void IRAM_ATTR onTimer()
{
  countTimer++;
  if (countTimer>SERVO_TOTAL_TICKS)
  {
    countTimer=0;  
    for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
    {
      if (servos[i]>-1)
      {
        digitalWrite(servos[i], 1);
      }
    }
  }
  if (countTimer>=SERVO_CONTROL_INF && countTimer<=SERVO_CONTROL_SUP)
  {
    for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
    {
      if (servos[i]>-1)
      {
        if (servo_boundery[i]<=countTimer)
        {
          digitalWrite(servos[i], 0);
        }
      }
    }
  }
}

void ServoController::begin()
{
  for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
  {
    if (servos[i]>0) pinMode(servos[i], OUTPUT);
  }
  hw_timer= timerBegin(0, 20, true);
  timerAttachInterrupt(hw_timer, &onTimer, true);
  timerAlarmWrite(hw_timer, 100, true);
  timerAlarmEnable(hw_timer);
}

void ServoController::set(uint8_t servo, uint16_t value)
{
    servo_boundery[servo] = value;
}