/**

 * Function List:
 *
 *    1. void TKEncoderMotor::begin();
 *    2. boolean TKEncoderMotor::runSpeedAndTime(float speed, float time);

 */

#include "TKOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>

TKEncoderNew motor2(0x09, SLOT2);   //  motor at slot2

void setup()
{
  motor2.begin();
  Serial.begin(9600);
}

void loop()
{
  motor2.runSpeedAndTime(200,5);
  motor2.runSpeedAndTime(-100,5);
}
