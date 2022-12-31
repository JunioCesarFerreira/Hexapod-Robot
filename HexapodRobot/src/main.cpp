#include <Arduino.h>

void setup() 
{
	Serial.begin(921600);
  Serial.print("\n\nServo initial test...\n");
  pinMode(1, OUTPUT);
}

void loop() 
{
  static bool dir = true;
  static uint32_t t1=1000;
  const uint32_t  step = 5;

  if (t1<=500) dir = true; // minimum that generates response
  if (t1>=2600) dir = false; // maximum that generates response

  if (dir) t1+=step;
  else t1-=step;

  uint32_t t2=20000-t1;
  digitalWrite(1, 1);
  ets_delay_us(t1);
  digitalWrite(1, 0);
  ets_delay_us(t2);
}