
#ifndef TKRGBLed_h
#define TKRGBLed_h
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"

#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif // TK_PORT_DEFINED

#define DEFAULT_MAX_LED_NUMBER  (32)

/// @brief Class for RGB Led Module
struct cRGB
{
  uint8_t g;
  uint8_t r;
  uint8_t b;
};

/**
 * Class: TKRGBLed
 *
 * \par Description
 * Declaration of Class TKRGBLed
 */
#ifndef TK_PORT_DEFINED
class TKRGBLed
#else // !TK_PORT_DEFINED
class TKRGBLed : public TKPort
#endif // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the TKRGBLed to arduino port,
 * no pins are used or initialized here, it only assigned the LED display buffer. The default
 *number of light strips is 32.
 * \param[in]
 *   None
 */
  TKRGBLed(void);

/**
 * Alternate Constructor which can call your own function to map the TKRGBLed to arduino port,
 * it will assigned the LED display buffer and initialization the GPIO of LED lights. The slot2
 * will be used here, and the default number of light strips is 32.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKRGBLed(uint8_t port);

/**
 * Alternate Constructor which can call your own function to map the TKRGBLed to arduino port,
 * it will assigned the LED display buffer and initialization the GPIO of LED lights. The slot2
 * will be used here, you can reset the LED number by this constructor.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   led_num - The LED number
 */
  TKRGBLed(uint8_t port, uint8_t led_num);

/**
 * Alternate Constructor which can call your own function to map the TKRGBLed to arduino port,
 * it will assigned the LED display buffer and initialization the GPIO of LED lights. You can
 * set any slot for the LED data PIN, and reset the LED number by this constructor.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 * \param[in]
 *   led_num - The LED number
 */

  TKRGBLed(uint8_t port, uint8_t slot, uint8_t led_num);
#else //TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the TKRGBLed to arduino port,
 * it will assigned the LED display buffer and initialization the GPIO of LED lights. You can
 * set any arduino digital pin for the LED data PIN, The default number of light strips is 32.
 * \param[in]
 *   port - arduino port
 */
  TKRGBLed(uint8_t port);

/**
 * Alternate Constructor which can call your own function to map the TKRGBLed to arduino port,
 * it will assigned the LED display buffer and initialization the GPIO of LED lights. You can
 * set any arduino digital pin for the LED data PIN, and reset the LED number by this constructor.
 * \param[in]
 *   port - arduino port
 * \param[in]
 *   led_num - The LED number
 */
  TKRGBLed(uint8_t port, uint8_t led_num);
#endif //TK_PORT_DEFINED
/**
 * Destructor which can call your own function, it will release the LED buffer
 */
  ~TKRGBLed(void);

#ifdef TK_PORT_DEFINED
/**
 * \par Function
 *   reset
 * \par Description
 *   Reset the LED available data PIN by its RJ25 port, and slot2 will be used as default.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void reset(uint8_t port);

/**
 * \par Function
 *   reset
 * \par Description
 *   Reset the LED available data PIN by its RJ25 port and slot.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void reset(uint8_t port,uint8_t slot);
#endif //TK_PORT_DEFINED
/**
 * \par Function
 *   setpin
 * \par Description
 *   Reset the LED available data PIN by its arduino port.
 * \param[in]
 *   port - arduino port(should digital pin)
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void setpin(uint8_t port);

/**
 * \par Function
 *   getNumber
 * \par Description
 *   Get the LED number you can light it.
 * \par Output
 *   None
 * \return
 *   The total number of LED's
 * \par Others
 *   The index value from 1 to the max
 */
  uint8_t getNumber(void);

/**
 * \par Function
 *   getColorAt
 * \par Description
 *   Get the LED color value from its index
 * \param[in]
 *   index - The LED index number you want to read its value
 * \par Output
 *   None
 * \return
 *   The LED color value, include the R,G,B
 * \par Others
 *   The index value from 1 to the max
 */
  cRGB getColorAt(uint8_t index);

/**
 * \par Function
 *   fillPixelsBak
 * \par Description
 *   fill the LED color data to pixels_bak.
 * \param[in]
 *   red - Red values
 * \param[in]
 *   green - green values
 * \param[in]
 *   blue - blue values
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void fillPixelsBak(uint8_t red, uint8_t green, uint8_t blue);

/**
 * \par Function
 *   setColorAt
 * \par Description
 *   Set the LED color for any LED.
 * \param[in]
 *   index - The LED index number you want to set its color
 * \param[in]
 *   red - Red values
 * \param[in]
 *   green - green values
 * \param[in]
 *   blue - blue values
 * \par Output
 *   None
 * \return
 *   TRUE: Successful implementation
 *   FALSE: Wrong execution
 * \par Others
 *   The index value from 0 to the max.
 */
bool setColorAt(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

/**
 * \par Function
 *   setColor
 * \par Description
 *   Set the LED color for any LED.
 * \param[in]
 *   index - The LED index number you want to set its color
 * \param[in]
 *   red - Red values
 * \param[in]
 *   green - green values
 * \param[in]
 *   blue - blue values
 * \par Output
 *   None
 * \return
 *   TRUE: Successful implementation
 *   FALSE: Wrong execution
 * \par Others
 *   The index value from 1 to the max, if you set the index 0, all the LED will be lit
 */
  bool setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);

/**
 * \par Function
 *   setColor
 * \par Description
 *   Set the LED color for all LED.
 * \param[in]
 *   red - Red values
 * \param[in]
 *   green - green values
 * \param[in]
 *   blue - blue values
 * \par Output
 *   None
 * \return
 *   TRUE: Successful implementation
 *   FALSE: Wrong execution
 * \par Others
 *   All the LED will be lit.
 */
  bool setColor(uint8_t red, uint8_t green, uint8_t blue);

/**
 * \par Function
 *   setColor
 * \par Description
 *   Set the LED color for any LED.
 * \param[in]
 *   value - the LED color defined as long type, for example (white) = 0xFFFFFF
 * \par Output
 *   None
 * \return
 *   TRUE: Successful implementation
 *   FALSE: Wrong execution
 * \par Others
 *   The index value from 1 to the max, if you set the index 0, all the LED will be lit
 */
  bool setColor(uint8_t index, long value);

/**
 * \par Function
 *   setNumber
 * \par Description
 *   Assigned the LED display buffer by the LED number
 * \param[in]
 *   num_leds - The LED number you used
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void setNumber(uint8_t num_led);

/**
 * \par Function
 *   show
 * \par Description
 *   Transmission the data to WS2812
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void show(void);

private:
  uint16_t count_led;
  uint8_t *pixels;
  uint8_t *pixels_bak;

/**
 * \par Function
 *   rgbled_sendarray_mask
 * \par Description
 *   Set the LED color for any LED.
 * \param[in]
 *   *data - the LED color store memory address
 * \param[in]
 *   datlen - the data length need to be transmitted.
 * \param[in]
 *   maskhi - the gpio pin mask
 * \param[in]
 *   *port - the gpio port address
 * \par Output
 *   None
 * \return
 *   TRUE: Successful implementation
 *   FALSE: Wrong execution
 * \par Others
 *   None
 */
  void rgbled_sendarray_mask(uint8_t *array, uint16_t length, uint8_t pinmask, uint8_t *port);

  const volatile uint8_t *ws2812_port;
  volatile uint8_t *ws2812_port_reg;
  uint8_t pinMask;
};
#endif
