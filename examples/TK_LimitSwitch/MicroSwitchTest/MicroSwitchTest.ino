/**
 * Function List:
 *    1. void    bool MeLimitSwitch::touched();
 */

/* Includes ------------------------------------------------------------------*/
#include "TKOrion.h"

/* Private functions ---------------------------------------------------------*/
/* TK_LimitSwitch module can only be connected to PORT_3, PORT_4, PORT_6, 
// PORT_7,PORT_8 of base shield or from PORT_3 to PORT_8 of baseboard. */
TKLimitSwitch limitSwitch1(PORT_3, SLOT1);      // connecte to Me RJ25 Adapter SLOT1
TKLimitSwitch limitSwitch2(PORT_3, SLOT2);      // connecte to Me RJ25 Adapter SLOT2


void setup()
{
  Serial.begin(9600);
  Serial.println("Start.");
}

void loop()
{
  if(limitSwitch1.touched() )     // If the limit switch is touched, the  return value is true.
  {
    delay(10);
    Serial.println("limitSwitch1 DOWN.");
  }
  if(limitSwitch2.touched() )     // If the limit switch is touched, the  return value is true.
  {
    delay(10);
    Serial.println("limitSwitch2 DOWN.");
  }
}
