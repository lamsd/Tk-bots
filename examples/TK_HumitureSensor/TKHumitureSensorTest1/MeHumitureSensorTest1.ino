/**
 * Function List:
 *    1. void TKHumiture::update(void)
 *    2. uint8_t TKHumiture::getHumidity(void)
 *    3. uint8_t TKHumiture::getTemperature(void)
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
  Serial.print( humiture.getHumidity() );
  Serial.print(", Temperature (oC) =");
  Serial.println( humiture.getTemperature() );
  Serial.println("###########################");
  delay(1000);
}
