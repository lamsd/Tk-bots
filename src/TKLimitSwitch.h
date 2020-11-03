

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef TKLimitSwitch_H
#define TKLimitSwitch_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"

#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif // TK_PORT_DEFINED

/* Exported classes ----------------------------------------------------------*/
/**
 * Class: TKLimitSwitch
 * \par Description
 * Declaration of Class TKLimitSwitch.
 */
#ifndef TK_PORT_DEFINED
class TKLimitSwitch
#else // !TK_PORT_DEFINED
class TKLimitSwitch : public TKPort
#endif  // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  TKLimitSwitch(void);

/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * the slot2 will be used here.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKLimitSwitch(uint8_t port);

/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * you can set any slot for the limit switch device. 
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 */
  TKLimitSwitch(uint8_t port, uint8_t slot);
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * \param[in]
 *   switchPin - arduino port for switch detect pin.
 */
  TKLimitSwitch(uint8_t switchPin);
#endif  // TK_PORT_DEFINED
/**
 * \par Function
 *    setpin
 * \par Description
 *    Reset the limit switch available PIN by its arduino port.
 * \param[in]
 *    switchPin - arduino port for switch detect pin.
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  void setpin(uint8_t switchPin);

/**
 * \par Function
 *    touched
 * \par Description
 *    Get switch value from selected _slot defined by TKPort.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \Return
 *    True if module is touched.
 * \par Others
 *    None
 */
  bool touched(void);

private:
  uint8_t _switchPin;
};
#endif
