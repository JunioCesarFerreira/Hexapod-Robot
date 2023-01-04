#include <ServoController.h>
#include <Leg.hpp>

ServoController servoControl;
HexaLegs hexaLegs;

void setup() 
{
	Serial.begin(921600);
  Serial.print("\n\nHexapod Robot tests.\nstart position...\n");

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
  hexaLegs.L1 = Leg(9,10,11, &servoControl);
  hexaLegs.L2 = Leg(12,13,14, &servoControl);
  hexaLegs.L3 = Leg(15,16,17, &servoControl);

  hexaLegs.moveAll(50,5,1);
  delay(3000);

  Serial.print("begin legs test...\n");
}

void loop() 
{
  // single leg movement test.
  hexaLegs.R1.moveTo(25,25,5,20);
  hexaLegs.R1.moveTo(25,65,25,20);
  hexaLegs.R1.moveTo(65,65,25,20);
  hexaLegs.R1.moveTo(65,45,15,20);

/*
  // checking tibia joint.
  hexaLegs.moveAll(50,5,1,60);
  hexaLegs.waitMotion();
  hexaLegs.moveAll(50,5,20,40);
  hexaLegs.waitMotion();
  delay(3000);
  hexaLegs.moveAll(50,5,50,40);
  hexaLegs.waitMotion();
  delay(3000);

  // standing up for the first time!
  hexaLegs.moveAll(50,5,1,60);
  hexaLegs.waitMotion();
  hexaLegs.moveAll(50,50,20,60);
  hexaLegs.waitMotion();
  delay(3000);
*/
}