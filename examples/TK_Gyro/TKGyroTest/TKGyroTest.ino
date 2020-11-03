/**
 * Function List:
 * 1. void TKGyro::begin(void)
 * 2. void TKGyro::update(void) 
 * 3. double TKGyro::angleX(void)
 * 4. double TKGyro::angleY(void)
 * 5. double TKGyro::angleZ(void)
 */
#include "TKOrion.h"
#include <Wire.h>

TKGyro gyro;
void setup()
{
  Serial.begin(115200);
  gyro.begin();
}

void loop()
{
  gyro.update();
  Serial.read();
  Serial.print("X:");
  Serial.print(gyro.getAngleX() );
  Serial.print(" Y:");
  Serial.print(gyro.getAngleY() );
  Serial.print(" Z:");
  Serial.println(gyro.getAngleZ() );
  delay(10);
}
