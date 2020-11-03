

/* Includes ------------------------------------------------------------------*/
#include "TKLimitSwitch.h"


/* Private functions ---------------------------------------------------------*/
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
TKLimitSwitch::TKLimitSwitch(void) : TKPort(0)
{

}

/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * the slot2 will be used here.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
TKLimitSwitch::TKLimitSwitch(uint8_t port) : TKPort(port)
{
  pinMode(s2, INPUT_PULLUP);
}

/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * you can set any slot for the limit switch device. 
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 */
TKLimitSwitch::TKLimitSwitch(uint8_t port, uint8_t slot) : TKPort(port)
{
  reset(port, slot);
  if (getSlot() == SLOT1)
  {
    pinMode(s1, INPUT_PULLUP);
  }
  else
  {
    pinMode(s2, INPUT_PULLUP);
  }
}
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the limit switch to arduino port,
 * \param[in]
 *   switchPin - arduino port for switch detect pin.
 */
TKLimitSwitch::TKLimitSwitch(uint8_t switchPin)
{
  _switchPin = switchPin;
  pinMode(s2, INPUT_PULLUP);
}
#endif // TK_PORT_DEFINED

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
void TKLimitSwitch::setpin(uint8_t switchPin)
{
  _switchPin = switchPin;
  pinMode(_switchPin, INPUT_PULLUP);
#ifdef TK_PORT_DEFINED
  if (getSlot() == SLOT1)
  {
    s1 = switchPin;
  }
  else
  {
    s2 = switchPin;
  }
#endif // TK_PORT_DEFINED
}

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
bool TKLimitSwitch::touched(void)
{
#ifdef TK_PORT_DEFINED
  return(!(getSlot() == SLOT1 ? digitalRead(s1) : digitalRead(s2)));
#else // TK_PORT_DEFINED
  return digitalRead(_switchPin);
#endif // TK_PORT_DEFINED
}

