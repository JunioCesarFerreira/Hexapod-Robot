#include <Arduino.h>

hw_timer_t *hw_timer = NULL;
uint16_t countTimer = 0;

#define TOTAL_TICKS    800 // 1 Tick = 50 us
#define SERVO_CONT_INF  20 // 500 us 
#define SERVO_CONT_SUP 104 // 2600 us
#define SERVOS_AMOUNT   18
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
  if (countTimer>TOTAL_TICKS)
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
  if (countTimer>=SERVO_CONT_INF && countTimer<=SERVO_CONT_SUP)
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

void setup() 
{
	Serial.begin(921600);
  Serial.print("\n\nHexapod Robot tests.\nbegin...\n");

  for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
  {
    if (servos[i]>0) pinMode(servos[i], OUTPUT);
  }

  hw_timer= timerBegin(0, 20, true);
  timerAttachInterrupt(hw_timer, &onTimer, true);
  timerAlarmWrite(hw_timer, 100, true);
  timerAlarmEnable(hw_timer);
}

void loop() 
{
  static bool dir = true;
  static uint32_t t1=1000;
  const uint32_t  step = 25;

  if (t1<=500) dir = true;
  if (t1>=2600) dir = false;

  if (dir) t1+=step;
  else t1-=step;

  for(uint8_t i=0;i<SERVOS_AMOUNT; i++)
  {
    servo_boundery[i] = t1 / step;
  }

  delay(60);
}