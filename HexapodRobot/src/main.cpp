#include <ServoController.h>
#include <Leg.hpp>

ServoController servoControl;
Legs legs;

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

  legs.R1 = Leg(0,1,2, &servoControl);
  legs.R2 = Leg(3,4,5, &servoControl);
  legs.R3 = Leg(6,7,8, &servoControl);
  legs.L1 = Leg(9,10,11, &servoControl);
  legs.L2 = Leg(12,13,14, &servoControl);
  legs.L3 = Leg(15,16,17, &servoControl);

  legs.setAll(50,5,1);
  delay(3000);

  Serial.print("begin legs test...\n");
}

void loop() 
{
  // single leg movement test.
  /*
  legs.R1.set(25,25,5,20);
  legs.R1.set(25,65,25,20);
  legs.R1.set(75,65,25,20);
  legs.R1.set(75,45,15,20);
  */

  // checking tibia joint.
  legs.setAll(50,5,1,60);
  delay(3000);
  legs.setAll(50,5,20,40);
  delay(3000);

  // standing up for the first time!
  legs.setAll(50,5,1,60);
  delay(3000);
  legs.setAll(50,50,20,60);
  delay(3000);
}