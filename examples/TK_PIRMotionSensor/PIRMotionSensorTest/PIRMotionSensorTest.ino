/**
 * Function List:
 * 1. void    TKPIRMotionSensor::SetPirMotionMode(uint8_t ModePin)
 * 2. bool    TKPIRMotionSensor::isHumanDetected();
 */

/* Includes ------------------------------------------------------------------*/
#include "TKOrion.h"

/* Private variables ---------------------------------------------------------*/
TKPIRMotionSensor myPIRsensor(PORT_3);

void setup()
{
  Serial.begin(9600);
  myPIRsensor.SetPirMotionMode(1);   //Continuous Trigger mode
}

void loop()
{
  if(myPIRsensor.isHumanDetected() )
  {
    Serial.println("People Motion Detected");
  }
  delay(20);
}
