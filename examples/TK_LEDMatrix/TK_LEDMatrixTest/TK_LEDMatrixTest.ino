/**
 * Function List:
 * 1. void TKLEDMatrix::setBrightness(uint8_t Bright);
 * 2. void TKLEDMatrix::setColorIndex(bool Color_Number);
 * 3. void TKLEDMatrix::drawStr(int16_t X_position, int8_t Y_position, const char *str);
 * 4. void TKLEDMatrix::showClock(uint8_t hour, uint8_t minute, bool point_flag)
 */
#include "TKOrion.h"

TKLEDMatrix ledMx(PORT_4);

void setup()
{
  ledMx.setBrightness(6);
  ledMx.setColorIndex(1);
}

char *s = "AB";

void loop()
{
  ledMx.showClock(12,03,1);
  delay(2000);
  ledMx.drawStr(0,7,s);
  delay(2000);
  ledMx.showNum(1.23);
  delay(2000);
}
