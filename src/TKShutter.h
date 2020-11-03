
#ifndef TKShutter_H
#define TKShutter_H
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"
#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif  /* TK_PORT_DEFINED */

/**
 * Class: TKShutter
 * \par Description
 * Declaration of Class TKShutter.
 */
#ifndef TK_PORT_DEFINED
class TKShutter
#else // !TK_PORT_DEFINED
class TKShutter : public TKPort
#endif // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the TKShutter to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  TKShutter(void);

/**
 * Alternate Constructor which can call your own function to map the TKShutter to arduino port,
 * and the shot and focus PIN will be set LOW
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKShutter(uint8_t port);
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the TKShutter to arduino port,
 * it will assigned the shot PIN and focus pin.
 * \param[in]
 *   ShotPin - arduino port for shot PIN(should digital pin)
 * \param[in]
 *   FocusPin - arduino port for focus PIN(should digital pin)
 */
  TKShutter(uint8_t ShotPin, uint8_t FocusPin);
#endif  // TK_PORT_DEFINED

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
  void setpin(uint8_t ShotPin, uint8_t FocusPin);

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
  void shotOn(void);

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
  void shotOff(void);

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
  void focusOn(void);

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
  void focusOff(void);

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
  void setState(uint8_t state);
private:
  volatile uint8_t  _ShotPin;
  volatile uint8_t  _FocusPin;
};
#endif

