
#ifndef TKHumitureSensor_H
#define TKHumitureSensor_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"

#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif // TK_PORT_DEFINED

/**
 * Class: TKHumiture
 * \par Description
 * Declaration of Class TKHumiture.
 */
#ifndef TK_PORT_DEFINED  
class TKHumiture
#else // !TK_PORT_DEFINED
class TKHumiture : public TKPort
#endif // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the humiture sensor to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  TKHumiture(void);
 
/**
 * Alternate Constructor which can call your own function to map the temperature sensor to arduino port,
 * the slot2 pin will be used here since specify slot is not be set.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKHumiture(uint8_t port);
#else // TK_PORT_DEFINED
/**
 * \par Function
 *   setpin
 * \par Description
 *   Reset available PIN for temperature sensor by its arduino port.
 * \param[in]
 *   port - arduino port(should digital pin)
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  TKHumiture(uint8_t port);
#endif // TK_PORT_DEFINED
  
/**
 * \par Function
 *   setpin
 * \par Description
 *   Reset available PIN for temperature sensor by its arduino port.
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
 *   update
 * \par Description
 *   Use this function to update the sensor data
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void update(void);

/**
 * \par Function
 *   getHumidity
 * \par Description
 *   Use this function to Get the Humidity data
 * \par Output
 *   None
 * \return
 *   The value of Humidity
 * \par Others
 *   None
 */
  uint8_t getHumidity(void);

/**
 * \par Function
 *   getTemperature
 * \par Description
 *   Use this function to Get the Temperature data
 * \par Output
 *   None
 * \return
 *   The value of Temperature
 * \par Others
 *   None
 */
  uint8_t getTemperature(void);

/**
 * \par Function
 *   getValue
 * \par Description
 *   Use this function to Get the Temperature data or Humidity data
 * \param[in]
 *   index - The value '0' means get the value of Humidity data and '1' used to get the
 *   Temperature data.
 * \par Output
 *   None
 * \return
 *   The value of Temperature
 * \par Others
 *   None
 */
  uint8_t getValue(uint8_t index);

/**
 * \par Function
 *    Fahrenheit
 * \par Description
 *    Change celsius degrees into Fahrenheit.
 * \param[in]
 *    celsius - The number of celsius degrees.
 * \par Output
 *    None
 * \par Return
 *    Return the number of Fahrenheit
 * \par Others
 *    None
 */
  double getFahrenheit(void);//Celsius degrees to Fahrenheit

/**
 * \par Function
 *    Kelvin
 * \par Description
 *    Change celsius degrees into Kelvin.
 * \param[in]
 *    celsius - The number of celsius degrees.
 * \par Output
 *    None
 * \par Return
 *    Return the number of Kelvin temperature.
 * \par Others
 *    None
 */
  double getKelvin(void);

/**
 * \par Function
 *    dewPoint
 * \par Description
 *    The dew-point temperature (Point at this temperature, the air is saturated and produce dew).
 * \param[in]
 *    celsius - The celsius degrees of air.
  * \param[in]
 *    humidity - The humidity of air.
 * \par Output
 *    None
 * \par Return
 *    Return the dew-point of air.
 * \par Others
 *    None
 */
  double getdewPoint(void);

/**
 * \par Function
 *    dewPointFast
 * \par Description
 *    Fast calculating dew point, Speed is 5 times to dewPoint().
 * \param[in]
 *    celsius - The celsius degrees of air.
  * \param[in]
 *    humidity - The humidity of air.
 * \par Output
 *    None
 * \par Return
 *    Return the Fast calculating dew point of air.
 * \par Others
 *    None
 */
  double getPointFast(void);

private:
  uint8_t Humidity;
  uint8_t Temperature;
  uint8_t  _DataPin;
};

#endif

