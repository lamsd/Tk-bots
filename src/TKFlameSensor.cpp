
#include "TKFlameSensor.h"

#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the flame snesor to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
TKFlameSensor::TKFlameSensor(void) : TKPort(0)
{

}

/**
 * Alternate Constructor which can call your own function to map the flame snesor to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
TKFlameSensor::TKFlameSensor(uint8_t port) : TKPort(port)
{

}
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the flame snesor to arduino port,
 * it will assigned the input pin for flame snesor.
 * \param[in]
 *   digital_pin - arduino port for digital signal input
 * \param[in]
 *   analog_pin - arduino port for analog signal input
 */
TKFlameSensor::TKFlameSensor(uint8_t digital_pin,uint8_t analog_pin)
{
  _digital_pin = digital_pin;
  _analog_pin = analog_pin;
  pinMode(_digital_pin, INPUT);
}
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
void TKFlameSensor::setpin(uint8_t digital_pin,uint8_t analog_pin)
{
  _digital_pin = digital_pin;
  _analog_pin = analog_pin;
  pinMode(_digital_pin, INPUT);
#ifdef TK_PORT_DEFINED
  s1 = _analog_pin;
  s2 = _digital_pin;
#endif // TK_PORT_DEFINED
}

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
uint8_t TKFlameSensor::readDigital(void)
{
#ifdef TK_PORT_DEFINED
  return( TKPort::dRead2() );
#else //TK_PORT_DEFINED
  return digitalRead(_digital_pin);
#endif //TK_PORT_DEFINED
}

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
int16_t TKFlameSensor::readAnalog(void)
{
#ifdef TK_PORT_DEFINED
  return( TKPort::aRead1() );
#else //TK_PORT_DEFINED
  return analogRead(_analog_pin);
#endif //TK_PORT_DEFINED
}
