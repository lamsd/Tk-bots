
#include "TKShutter.h"

#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the TKShutter to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
TKShutter::TKShutter(void) : TKPort(0)
{

}

/**
 * Alternate Constructor which can call your own function to map the TKShutter to arduino port,
 * and the shot and focus PIN will be set LOW
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
TKShutter::TKShutter(uint8_t port) : TKPort(port)
{
  TKPort::dWrite1(LOW);
  TKPort::dWrite2(LOW);
}
#else //TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the TKShutter to arduino port,
 * it will assigned the shot PIN and focus pin.
 * \param[in]
 *   ShotPin - arduino port for shot PIN(should digital pin)
 * \param[in]
 *   FocusPin - arduino port for focus PIN(should digital pin)
 */
TKShutter::TKShutter(uint8_t ShotPin, uint8_t FocusPin)
{
  _ShotPin = ShotPin;
  _FocusPin = FocusPin;

  //set pinMode OUTPUT
  pinMode(_ShotPin, OUTPUT);
  pinMode(_FocusPin, OUTPUT);
  digitalWrite(_ShotPin, LOW);
  digitalWrite(_FocusPin, LOW);
}
#endif // TK_PORT_DEFINED

/**
 * \par Function
 *   setpin
 * \par Description
 *   Reset the shutter available PIN by its arduino port.
 * \param[in]
 *   ShotPin - arduino port for shot PIN(should digital pin)
 * \param[in]
 *   FocusPin - arduino port for focus PIN(should digital pin)
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void TKShutter::setpin(uint8_t ShotPin, uint8_t FocusPin)
{
  _ShotPin = ShotPin;
  _FocusPin = FocusPin;

  //set pinMode OUTPUT
  pinMode(_ShotPin, OUTPUT);
  pinMode(_FocusPin, OUTPUT);
  digitalWrite(_ShotPin, LOW);
  digitalWrite(_FocusPin, LOW);
#ifdef TK_PORT_DEFINED
  s1 = _ShotPin;
  s2 = _FocusPin;
#endif
}

/**
 * \par Function
 *   shotOn
 * \par Description
 *   Set the shot PIN on
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void TKShutter::shotOn(void)
{
#ifdef TK_PORT_DEFINED
  TKPort::dWrite1(HIGH);
#else //TK_PORT_DEFINED
  digitalWrite(_ShotPin, HIGH);
#endif //TK_PORT_DEFINED
}

/**
 * \par Function
 *   shotOff
 * \par Description
 *   Set the shot PIN off
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void TKShutter::shotOff(void)
{
#ifdef TK_PORT_DEFINED
  TKPort::dWrite1(LOW);
#else //TK_PORT_DEFINED
  digitalWrite(_ShotPin, LOW);
#endif //TK_PORT_DEFINED
}

/**
 * \par Function
 *   focusOn
 * \par Description
 *   Set the focus PIN on
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void TKShutter::focusOn(void)
{
#ifdef TK_PORT_DEFINED
  TKPort::dWrite2(HIGH);
#else //TK_PORT_DEFINED
  digitalWrite(_FocusPin, HIGH);
#endif //TK_PORT_DEFINED
}

/**
 * \par Function
 *   focusOff
 * \par Description
 *   Set the focus PIN off
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void TKShutter::focusOff(void)
{
#ifdef TK_PORT_DEFINED
  TKPort::dWrite2(LOW);
#else //TK_PORT_DEFINED
  digitalWrite(_FocusPin, LOW);
#endif //TK_PORT_DEFINED
}

/**
 * \par Function
 *   focusOff
 * \par Description
 *   Set shutter device's work state.
 * \param[in]
 *   state - 0:shotOff\n
 *           1:shotOn\n
 *           2:focusOff\n
 *           3:focusOn\n
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void TKShutter::setState(uint8_t state)
{
  if(state < 2)
  {
#ifdef TK_PORT_DEFINED
    TKPort::dWrite1(state);
#else //TK_PORT_DEFINED
    digitalWrite(_ShotPin, state);
#endif //TK_PORT_DEFINED
  }
  else
  {
#ifdef TK_PORT_DEFINED
    TKPort::dWrite2(state - 2);
#else //TK_PORT_DEFINED
    digitalWrite(_FocusPin, (state - 2));
#endif //TK_PORT_DEFINED
  }
}

