/**
 * \par Method List:
 *  inherited from MeSerial
 */
#include "TKOrion.h"
#include <SoftwareSerial.h>

TKWifi Wifi(PORT_4);

void setup()
{
  Serial.begin(9600);
  Wifi.begin(9600);
  Serial.println("Wifi Start!");
}

void loop()
{
  char inDat;
  char outDat;
  if(Wifi.available() )
  {
    char c = Wifi.read();
    Serial.print(c);
  }
  if(Serial.available() )
  {
    outDat = Serial.read();
    Wifi.write(outDat);
  }
}
