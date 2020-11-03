/**
 * Function List:
 *    1. void TKHumiture::update(void)
 *    2. uint8_t TKHumiture::getHumidity(void)
 *    3. uint8_t TKHumiture::getTemperature(void)
 *    6. double TKHumiture::getFahrenheit(void)
 *    7. double TKHumiture::getKelvin(void)
 *    8. double TKHumiture::getdewPoint(void)
 *    9. double TKHumiture::getPointFast()
 */
#include "TKOrion.h"

TKHumiture humiture(PORT_6);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  humiture.update();
  Serial.print("Humidity (%) =");
  Serial.println( humiture.getHumidity() );
  Serial.print("Temperature (oC) =");
  Serial.println( humiture.getTemperature() );
  Serial.print("Fahrenheit (oF) =");
  Serial.println( humiture.getFahrenheit() );
  Serial.print("Kelvin (K) =");
  Serial.println( humiture.getKelvin() );
  Serial.print("dewPoint (oC) =");
  Serial.println( humiture.getdewPoint() );
  //Serial.print("dewPointFast=");
  //Serial.println( humiture.getPointFast() );
  Serial.println("###########################");
  delay(1000);
}
