/**
 * Function List:
 *    1. uint8_t TKFlameSensor::readDigital(void)
 *    2. TKFlameSensor::readAnalog(void)
 */
#include "TKOrion.h"

TKFlameSensor FlameSensor1(PORT_6);

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.print("Analog Value is: ");
  Serial.print(FlameSensor1.readAnalog());
  Serial.print("----Status: ");
  if(FlameSensor1.readDigital() == Fire)
  {
    Serial.println("Fire");
  }
  else if(FlameSensor1.readDigital() == NoFire)
  {
    Serial.println("NoFire");
  }
  delay(200);
}
