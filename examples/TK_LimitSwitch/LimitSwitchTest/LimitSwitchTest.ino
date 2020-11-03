/**

 * Function List:
 *    1. void    bool TKLimitSwitch::touched();

 */

/* Includes ------------------------------------------------------------------*/
#include "TKOrion.h"

/* Private variables ---------------------------------------------------------*/
// TK_LimitSwitch module can only be connected to PORT_3, PORT_4, PORT_6, PORT_7, 
// PORT_8 of base shield or from PORT_3 to PORT_8 of baseboard.
TKLimitSwitch limitSwitch(PORT_6);

/* Private functions ---------------------------------------------------------*/
void setup()
{
  Serial.begin(9600);
  Serial.println("Start.");
}

void loop()
{
  if(limitSwitch.touched() )      // If the limit switch is touched, the  return value is true.
  {
    Serial.println("State: DOWN.");
    delay(1);
    while(limitSwitch.touched() )
    {
      ;// Repeat check the switch state, until released.
    }
    delay(2);
  }
  if(!limitSwitch.touched() )
  {
    Serial.println("State: UP.");
    delay(1);
    while(!limitSwitch.touched() )
    {
      ;
    }
    delay(2);
  }
}
