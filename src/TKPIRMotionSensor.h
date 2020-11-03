

#ifndef TKPIRMotionSensor_H
#define TKPIRMotionSensor_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"

#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif  // TK_PORT_DEFINED

/**
 * Class: TKPIRMotionSensor
 * \par Description
 * Declaration of Class TKPIRMotionSensor.
 */
#ifndef TK_PORT_DEFINED
class TKPIRMotionSensor
#else // !TK_PORT_DEFINED
class TKPIRMotionSensor : public TKPort
#endif  // TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Motion Sensor device to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  TKPIRMotionSensor();

/**
 * Alternate Constructor which can call your own function to map the Motion Sensor device to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKPIRMotionSensor(uint8_t port);
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Motion Sensor device to arduino port
 * \param[in]
 *   ModePin - arduino port for BIS0001's A port
 * \param[in]
 *   SensorPin - arduino port for BIS0001's Vo port
 */
  TKPIRMotionSensor(uint8_t ModePin,uint8_t SensorPin);
#endif // TK_PORT_DEFINED
/**
 * \par Function
 *    setpin
 * \par Description
 *    Reset the PIR motion sensor available PIN by its arduino port.
 * \param[in]
 *   ModePin - arduino port for BIS0001's A port
 * \param[in]
 *   SensorPin - arduino port for BIS0001's Vo port
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    Set global variable _KeyPin and s2
 */
  void setpin(uint8_t ModePin,uint8_t SensorPin);

/**
 * \par Function
 *    SetPirMotionMode
 * \par Description
 *    Set PIR motion sensor's trigger mode.
 * \param[in]
 *    ModePin - 1: Retriggerable,   0: Unrepeatable trigger
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  void SetPirMotionMode(uint8_t ModePin);

/**
 * \par Function
 *    isHumanDetected
 * \par Description
 *    Is human been detected.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    ture: human is detected 
 *    false: no human been detected 
 * \par Others
 *    None
 */
  bool isHumanDetected();
private:
  static volatile uint8_t _SensorPin;
  static volatile uint8_t _ModePin;
};
#endif // TKPIRMotionSensor_H

