/**

 * Function List:
 *    1. bool TKTouchSensor::touched()
 *    2. void TKTouchSensor::SetTogMode(uint8_t TogMode)

 */
#include "TKOrion.h"

// Me_LimitSwitch module can only be connected to PORT_3, PORT_4, PORT_6,PORT_7,PORT_8 of base shield
// or from PORT_3 to PORT_8 of baseboard.
TKTouchSensor TKTouchSensor(PORT_6);

void setup()
{
  Serial.begin(9600);
  Serial.println("Start.");
  TKTouchSensor.SetTogMode(0);
}

void loop()
{
  if(TKTouchSensor.touched() )      // If the limit switch is touched, the  return value is true.
  {
    Serial.println("State: DOWN.");
    delay(1);
    while(TKTouchSensor.touched() )
    {
      ;                             // Repeat check the switch state, until released
    }
    delay(2);
  }
  if(!TKTouchSensor.touched() )
  {
    Serial.println("State: UP.");
    delay(1);
    while(!TKTouchSensor.touched() )
    {
      ;
    }
    delay(2);
  }
}
