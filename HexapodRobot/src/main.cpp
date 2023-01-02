#include <ServoController.h>

ServoController servoControl;

void setup() 
{
	Serial.begin(921600);
  Serial.print("\n\nHexapod Robot tests.\nbegin...\n");

  servoControl.begin();
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
    servoControl.set(i, t1/step);
  }

  delay(20);
}