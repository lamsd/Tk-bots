/**

 * Function List:
 *
 *    1. void TKEncoderMotor::begin();
 *    2. boolean TKEncoderMotor::moveTo(float angle, float speed);
 *    3. void TKEncoderNew::setCurrentPosition(long pulse_counter);
 *    4. long TKEncoderNew::getCurrentPosition();
 *    5. boolean TKEncoderNew::isTarPosReached(void);

 */

#include "TKOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>

TKEncoderNew motor2(0x09, SLOT2);   //  motor at slot2

void setup()
{
  motor2.begin();
  Serial.begin(9600);
  motor2.setCurrentPosition(0);
}

void loop()
{
  motor2.moveTo(2000, 200);
  while(motor2.isTarPosReached() == false)
  {
    Serial.print("pos: ");
    Serial.println(motor2.getCurrentPosition());
  }
  motor2.moveTo(0, 200);
  while(motor2.isTarPosReached() == false)
  {
    Serial.print("pos: ");
    Serial.println(motor2.getCurrentPosition());
  }
}
