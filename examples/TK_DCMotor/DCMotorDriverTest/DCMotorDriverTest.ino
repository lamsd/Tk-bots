/**

 * Function List:
 *    1. void TKDCMotor::run(int16_t speed)
 *    2. void TKDCMotor::stop(void)
  */
#include "TKOrion.h"

TKDCMotor motor1(PORT_1);

TKDCMotor motor2(PORT_2);

TKDCMotor motor3(M1);

TKDCMotor motor4(M2);

uint8_t motorSpeed = 100;

void setup()
{
}

void loop()
{
  motor1.run(motorSpeed); /* value: between -255 and 255. */
  motor2.run(motorSpeed); /* value: between -255 and 255. */
  motor3.run(motorSpeed);
  motor4.run(motorSpeed);
  delay(2000);
  motor1.stop();
  motor2.stop();
  motor3.stop();
  motor4.stop();
  delay(100);
  motor1.run(-motorSpeed);
  motor2.run(-motorSpeed);
  motor3.run(-motorSpeed);
  motor4.run(-motorSpeed);
  delay(2000);
  motor1.stop();
  motor2.stop();
  motor3.stop();
  motor4.stop();
  delay(2000);
}
