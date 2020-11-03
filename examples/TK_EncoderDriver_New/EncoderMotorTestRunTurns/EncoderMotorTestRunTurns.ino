/**

 * Function List:
 *
 *    1. void TKEncoderMotor::begin();
 *    2. boolean TKEncoderMotor::runTurns(float turns, float speed);

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
  motor2.runTurns(5,100);
  delay(9000);
}
