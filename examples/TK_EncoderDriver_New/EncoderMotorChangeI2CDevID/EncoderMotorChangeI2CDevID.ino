/**

 * Function List:
 *
 *    1. void TKEncoderMotor::begin();
 *    2. boolean TKEncoderMotor::setDevid(float turns, float speed);

 */

#include "TKOrion.h"
#include <Wire.h>
#include <SoftwareSerial.h>

//If you do not know the address of the current motor encoder, you can use
//example code -> I2CScan -> TK_I2CScanTest to get the I2C address.

TKEncoderNew motor2(0x09, SLOT2);   //  motor at slot2

//This sample code is only used to modify the coding of the motor I2C address
//Steps for usage:
//1. programmed this code into the Orion Board.(parameter of setDevid is the address need to be set)
//2. Linked to the encoder motor driver board through I2C bus (RJ25 cable)
//3. Orion board must have an external power supply, and the switch is on.
//4. reset the Orion Board.
//5. When Orion board print OK, Unplug the I2C bus
//6. reset the Encoder driver board.
void setup()
{
  delay(10);
  motor2.begin();
  Serial.begin(9600);
  delay(10);
  motor2.setDevid(0x0a);
}

void loop()
{
  Serial.println("OK");
  delay(9000);
}
