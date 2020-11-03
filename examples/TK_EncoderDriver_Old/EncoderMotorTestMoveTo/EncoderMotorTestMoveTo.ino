/**

 * Function List:
 *
 *    1. void TKEncoderMotor::begin();
 *    2. boolean TKEncoderMotor::moveTo(float angle, float speed);

 */

#include "TKOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>

TKEncoderMotor motor1(0x09, SLOT1);   //  Motor at slot1
TKEncoderMotor motor2(0x09, SLOT2);   //  motor at slot2

void setup()
{
  motor1.begin();
  motor2.begin();
  Serial.begin(9600);
}

void loop()
{
  motor2.moveTo(360, 200);
  motor1.moveTo(360, 200);
  delay(2000);
  motor2.moveTo(0, 100);
  motor1.moveTo(0, 100);
  delay(2000);
}
