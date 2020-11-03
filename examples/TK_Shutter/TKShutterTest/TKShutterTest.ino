/**
 * Function List:
 * 1. void TKShutter::shotOn()
 * 2. void TKShutter::shotOff()
 * 3. void TKShutter::focusOn()
 * 4. void TKShutter::focusOff()
 */
#include "TKOrion.h"

// MeShutter module can only be connected to the PORT_3, PORT_4, PORT_6 on Orion board
TKShutter myshutter(PORT3);

void setup()
{
  /* initialize serial communications at 9600 bps */
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available())
  {
    char a = Serial.read();
    if(a == 's')
    {
      myshutter.focusOn();
      delay(1000);
      myshutter.shotOn();
      delay(200);
      myshutter.shotOff();
      myshutter.focusOff();
    }
    if(a == 'f')
    {
      myshutter.focusOn();
      delay(1500);
      myshutter.focusOff();
    }
  }
}
