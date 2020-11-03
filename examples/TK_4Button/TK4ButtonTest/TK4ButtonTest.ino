/**

 * Function List:
 * 1. uint8_t TK4Button::pressed()
 
 */

/* Includes ------------------------------------------------------------------*/
#include <TKOrion.h>

/* Private variables ---------------------------------------------------------*/

/**
 * TK4Button module can only be connected to PORT_6, PORT_7, PORT_8 on base 
 * shield and Orion board.
 */
TK4Button btn(PORT_8);
// TK4Button module can only be connected to PORT_6,
// PORT_7, PORT_8 on base shield and Orion board.
uint8_t keyPressed = KEY_NULL;
uint8_t keyPressedPrevious = KEY_NULL;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  keyPressedPrevious = keyPressed;
  keyPressed = btn.pressed();
  if (keyPressedPrevious != keyPressed)
  {
    if (keyPressed == KEY_1)
    {
      Serial.println("KEY1 pressed");
    }
    if (keyPressed == KEY_2)
    {
      Serial.println("KEY2 pressed");
    }
    if (keyPressed == KEY_3)
    {
      Serial.println("KEY3 pressed");
    }
    if (keyPressed == KEY_4)
    {
      Serial.println("KEY4 pressed");
    }
    if (keyPressed == KEY_NULL)
    {
      Serial.println("KEY NULL");
    }
  }
}
