

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef TK4Button_H
#define TK4Button_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"

#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif //  TK_PORT_DEFINED

/* Exported macro ------------------------------------------------------------*/
#define KEY_NULL   (0)
#define KEY_1      (1)
#define KEY_2      (2)
#define KEY_3      (3)
#define KEY_4      (4)

#define KEY_NULL_VALUE   (962)     // 1023*((5-0.3)/5)
#define KEY_1_VALUE      (0)
#define KEY_2_VALUE      (481)     // 962/2
#define KEY_3_VALUE      (641)     // 962*2/3
#define KEY_4_VALUE      (721)     // 962*3/4

#define DEBOUNCED_INTERVAL (8)
// If you want key response faster, you can set DEBOUNCED_INTERVAL to a
// smaller number.

#define FALSE  (0)
#define TRUE   (1)

/**
 * Class: TK4Button
 * \par Description
 * Declaration of Class TK4Button
 */
#ifndef TK_PORT_DEFINED
class TK4Button
#else // !TK_PORT_DEFINED
class TK4Button : public TKPort
#endif // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 *  Alternate Constructor which can call your own function to map the TK4Button to arduino port, \n
 *  no pins are used or initialized here.
 * \param[in]
 *    None
 */
  TK4Button(void);
  
/**
 *  Alternate Constructor which can call your own function to map the TK4Button to arduino port, \n
 *  the slot2 pin will be used for key pin.
 * \param[in]
 *    port - RJ25 port from PORT_1 to M2
 */
  TK4Button(uint8_t port);
#else //  TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the _KeyPin to arduino port,
 * \param[in]
 *    port - arduino gpio number
 */
  TK4Button(uint8_t port);
#endif  //  TK_PORT_DEFINED
/**
 * \par Function
 *    setpin
 * \par Description
 *    Set the PIN for button module.
 * \param[in]
 *    port - arduino gpio number
 * \par Output
 *    None
 * \return
 *    None
 * \par Others
 *    None
 */
  void setpin(uint8_t port);

/**
 * \par Function
 *    pressed
 * \par Description
 *    Read key ADC value to a variable.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \return
 *    Return the key vlaue, the value maybe  KEY_1,KEY_2,KEY_3,KEY_4,KEY_NULL.
 * \par Others
 *    The key should periodically read, if it was delayed, It will affect the sensitivity of the keys
 */
  uint8_t pressed(void);
private:
  volatile unsigned long previous_time;
  volatile unsigned long key_debounced_count;
  volatile unsigned long key_match_count;
  volatile unsigned long key_debounced_value;
  volatile int16_t  Pre_Button_Value;
  volatile uint8_t  _KeyPin;
};
#endif // TK4Button_H
