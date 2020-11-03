/**

 * Function List:
 * 1. void TKCompass::init(void)
 * 2. double TKCompass::getAngle(void)

 */
#include "TKOrion.h"
#include <Wire.h>

TKCompass Compass(PORT_4);

void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing I2C devices...");
  Compass.begin();
  Serial.println("Testing device connections...");
  Serial.println(Compass.testConnection() ? "HMC5883L connection successful" : "HMC5883L connection failed");
}

void loop()
{
  int16_t head_X, head_Y, head_Z;
  double angle_number = 0;
  
  head_X = Compass.getHeadingX();
  head_Y = Compass.getHeadingY();
  head_Z = Compass.getHeadingZ();

  angle_number = Compass.getAngle();
  Serial.println(angle_number, 1);
  delay(500);
}
