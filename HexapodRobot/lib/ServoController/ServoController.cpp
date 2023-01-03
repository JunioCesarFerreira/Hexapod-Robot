#include "ServoController.h"

hw_timer_t *hw_timer = NULL;
uint16_t countTimer = 0;
uint16_t servos_boundery[SERVOS_AMOUNT];
int8_t servos_pinout[SERVOS_AMOUNT];

void IRAM_ATTR onTimer()
{
  countTimer++;
  if (countTimer>SERVO_TOTAL_TICKS)
  {
    countTimer=0;  
    for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
    {
      if (servos_pinout[i]>-1)
      {
        digitalWrite(servos_pinout[i], 1);
      }
    }
  }
  if (countTimer>=SERVO_CONTROL_INF && countTimer<=SERVO_CONTROL_SUP)
  {
    for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
    {
      if (servos_pinout[i]>-1)
      {
        if (servos_boundery[i]<=countTimer)
        {
          digitalWrite(servos_pinout[i], 0);
        }
      }
    }
  }
}

void ServoController::begin(const int8_t servo_pinout[SERVOS_AMOUNT])
{
  for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
  {
    servos_pinout[i] = servo_pinout[i];
    if (servos_pinout[i]>0) pinMode(servos_pinout[i], OUTPUT);
  }
  hw_timer= timerBegin(0, 20, true);
  timerAttachInterrupt(hw_timer, &onTimer, true);
  timerAlarmWrite(hw_timer, 100, true);
  timerAlarmEnable(hw_timer);
}

void ServoController::set(uint8_t servo, uint16_t value)
{
    servos_boundery[servo] = value;
}