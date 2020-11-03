/**
 * Function List:
 * 1. bool TKRGBLed::setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) 
 * 2. void TKRGBLed::show()
 */

#include "TKOrion.h"

TKRGBLed led1(PORT_3, SLOT1, 15);   /* parameter description: port, slot, led number */
TKRGBLed led2(PORT_3, SLOT2, 15);

int16_t bri = 0, st = 0;

void setup()
{

}

void loop()
{
  if(bri >= 100)
  {
    st = 1;
  }
  if(bri <= 0)
  {
    st = 0;
  }

  if(st)
  {
    bri--;
  }
  else
  {
    bri++;
  }
  for(int16_t t = 0; t < 15; t++)
  {
    led1.setColorAt(t, bri, bri, bri); /* parameter description: led number, red, green, blue, flash mode */
    led2.setColorAt(t, bri, bri, bri);
  }
  led1.show();
  led2.show();
  delay(20);
}
