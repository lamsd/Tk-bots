/**

 * Function List:
 *    1. void    TK7SegmentDisplay::display(int16_t value)
 
 */
#include "TKOrion.h"

TK7SegmentDisplay disp(PORT_6);

int i = 0;
void setup()
{
}

void loop()
{
  if(i > 100)
  {
    i = 0;
  }
  disp.display(i++);
  delay(100);
}
