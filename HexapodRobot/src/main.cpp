#include <ServoController.h>
#include <Leg.hpp>
#include <HexaMotion.hpp>

ServoController servoControl;
HexaLegs hexaLegs;
HexaMotion hexaMotion(&hexaLegs);

void setup() 
{
	Serial.begin(921600);
  Serial.print("\n\nHexapod Robot tests.\n");

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

  hexaLegs.R1 = Leg(0,1,2, &servoControl);
  hexaLegs.R2 = Leg(3,4,5, &servoControl);
  hexaLegs.R3 = Leg(6,7,8, &servoControl);
  hexaLegs.L1 = Leg(15,16,17, &servoControl);
  hexaLegs.L2 = Leg(12,13,14, &servoControl);
  hexaLegs.L3 = Leg(9,10,11, &servoControl);

  hexaMotion.retractedPosition();
  delay(3000);

  hexaMotion.checkingTibiaJoint();
  hexaMotion.retractedPosition();
  hexaMotion.checkingFemurJoint();
  hexaMotion.retractedPosition();

  delay(3000);

  hexaMotion.standingUp();
  delay(3000);

  Serial.print("loop begin...\n");
}

void loop() 
{
  hexaMotion.tripodGaitCycle();
}