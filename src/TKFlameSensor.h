

#ifndef TKFlameSensor_H
#define TKFlameSensor_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"


#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif // TK_PORT_DEFINED

#define Fire   (0x00)
#define NoFire (0x01)

/**
 * Class: TKFlameSensor
 * \par Description
 * Declaration of Class TKFlameSensor
 */
#ifndef TK_PORT_DEFINED
class TKFlameSensor
#else // !TK_PORT_DEFINED
class TKFlameSensor : public TKPort
#endif  // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the flame snesor to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  TKFlameSensor(void);

/**
 * Alternate Constructor which can call your own function to map the flame snesor to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKFlameSensor(uint8_t port);
#else //TK_PORT_DEFINED
  TKFlameSensor(uint8_t digital_pin,uint8_t analog_pin);
#endif // TK_PORT_DEFINED
/**
 * \par Function
 *   setpin
 * \par Description
 *   Reset the flame snesor available PIN by its arduino port.
 * \param[in]
 *   digital_pin - arduino port for digital signal input
 * \param[in]
 *   analog_pin - arduino port for analog signal input
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void setpin(uint8_t digital_pin,uint8_t analog_pin);
/**
 * \par Function
 *   readDigital
 * \par Description
 *   Read the digital signal of flame snesor, It is the result of comparison between the threshold
 *   value and the analog output. The threshold value can be adjusted using a rheostat
 * \par Output
 *   None
 * \return
 *   true - The fire is detected \n
 *   false - No fire is detected
 * \par Others
 *   None
 */
  uint8_t readDigital(void);
  
/**
 * \par Function
 *   readAnalog
 * \par Description
 *   Read the analog signal of flame snesor.
 * \par Output
 *   None
 * \return
 *   The vlaue from flame snesor's analog output
 * \par Others
 *   None
 */
  int16_t readAnalog(void);
private:
  volatile uint8_t _digital_pin;
  volatile uint8_t _analog_pin;
};
#endif

