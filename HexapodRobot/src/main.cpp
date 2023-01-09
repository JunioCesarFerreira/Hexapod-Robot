#include <ServoController.h>
#include <Leg.hpp>
#include <HexaMotion.hpp>
#include <RgbPixel.hpp>

ServoController servoControl;
HexaLegs hexaLegs;
HexaMotion hexaMotion(&hexaLegs);
RgbPixelClass rgbPixel;

void setup() 
{
  Serial.begin(921600);
  Serial.print("\n\n\n\nHexapod Robot tests.\n");

  const int8_t servos_pinout[NUMBER_OF_SERVOS] =
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
    
  rgbPixel.begin();
  rgbPixel.set(RGB_RED);

  Serial.print("retracted position.\n");
  hexaMotion.retractedPosition();

  rgbPixel.set(RGB_YELLON);
  delay(3000);

  rgbPixel.set(RGB_RED);
  Serial.print("checking joints.\n");
  hexaMotion.checkingTibiaJoint();
  hexaMotion.checkingFemurJoint();

  Serial.print("standing up.\n");
  hexaMotion.standingUp();

  rgbPixel.set(RGB_YELLON);
  delay(3000);

  Serial.print("loop begin.\n");
  Serial.print("demonstration of walk gait:\n");
  Serial.print("tripod gait demo.\n");
}

void loop() 
{
  rgbPixel.set(RGB_BLUE);
  static uint8_t gaitDemo = 1;
  gaitDemo++;
  if (gaitDemo==4) gaitDemo=1;
  
  switch (gaitDemo)
  {
    case 1:
      rgbPixel.set(RGB_BLUE);
      Serial.print("tripod gait demo.\n");
      break;
    
    case 2:
      rgbPixel.set(RGB_GREEN);
      Serial.print("wave gait demo.\n");
      break;

    case 3:
      rgbPixel.set(RGB_CYAN);
      Serial.print("ripple gait demo.\n");
      break;
  }

  switch (gaitDemo)
  {
    case 1:
      for (uint8_t i=0; i<3; i++) hexaMotion.tripodGaitCycle(10, true);
      hexaLegs.taskBreak();
      delay(1000);
      for (uint8_t i=0; i<3; i++) hexaMotion.tripodGaitCycle(10, false);
      hexaLegs.taskBreak();
      delay(1000);
      break;
  
    case 2:
      for (uint8_t i=0; i<3; i++) hexaMotion.waveGaitCycle(50, true);
      hexaLegs.taskBreak();
      delay(1000);
      for (uint8_t i=0; i<3; i++) hexaMotion.waveGaitCycle(50, false);
      hexaLegs.taskBreak();
      delay(1000);
      break;
  
    case 3:
      for (uint8_t i=0; i<3; i++) hexaMotion.rippleGaitCycle(80, true);
      hexaLegs.taskBreak();
      delay(1000);
      for (uint8_t i=0; i<3; i++) hexaMotion.rippleGaitCycle(80, false);
      hexaLegs.taskBreak();
      delay(1000);
      break;
  }
}