#include <ServoController.h>
#include <Leg.hpp>
#include <HexaMotion.hpp>

ServoController servoControl;
HexaLegs hexaLegs;
HexaMotion hexaMotion(&hexaLegs);

void setup() 
{
	Serial.begin(921600);
  Serial.print("\n\n\n\nHexapod Robot tests.\n");

  const int8_t servos_pinout[SERVOS_AMOUNT] =
  {
    1, 2, 3,    // Righ Leg 1
    4, 5, 6,    // Righ Leg 2 
    7, 8, 9,    // Righ Leg 3
    10, 11, 12, // Left Leg 1
    13, 14, 15, // Left Leg 2
    16, 17, 21  // Left Leg 3
  };

  servoControl.begin(servos_pinout);

  hexaLegs.R1 = HikingLeg(0,1,2, &servoControl);
  hexaLegs.R2 = HikingLeg(3,4,5, &servoControl);
  hexaLegs.R3 = HikingLeg(6,7,8, &servoControl);
  hexaLegs.L1 = HikingLeg(15,16,17, &servoControl);
  hexaLegs.L2 = HikingLeg(12,13,14, &servoControl);
  hexaLegs.L3 = HikingLeg(9,10,11, &servoControl);

  Serial.print("retracted position.\n");
  hexaMotion.retractedPosition();
  delay(3000);

  Serial.print("standing up.\n");
  hexaMotion.standingUp();
  delay(3000);

  Serial.print("loop begin.\n");
  Serial.print("demonstration of walk gait:\n");
  Serial.print("tripod gait demo.\n");
}

void loop() 
{
  static uint8_t count=0;
  static uint8_t gaitDemo = 1;
  count++;
  if (count>10)
  {
    count=0;
    gaitDemo++;
    if (gaitDemo==4)
    {
      gaitDemo=1;
    }
    switch (gaitDemo)
    {
      case 1:
        Serial.print("tripod gait demo.\n");
        break;
    
      case 2:
        Serial.print("wave gait demo.\n");
        break;

      case 3:
        Serial.print("ripple gait demo.\n");
        break;
    }
  }
  switch (gaitDemo)
  {
    case 1:
      hexaMotion.tripodGaitCycle();
      break;
  
    case 2:
      hexaMotion.waveGaitCycle();
      break;
  
    case 3:
      hexaMotion.rippleGaitCycle();
      break;
  }
}