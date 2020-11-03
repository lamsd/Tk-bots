
/* Includes ------------------------------------------------------------------*/
#include "TKPIRMotionSensor.h"

volatile uint8_t       TKPIRMotionSensor::_SensorPin        = 0;
volatile uint8_t       TKPIRMotionSensor::_ModePin          = 0;

/* Private functions ---------------------------------------------------------*/

/**
 * Alternate Constructor which can call your own function to map the Motion Sensor device to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
#ifdef TK_PORT_DEFINED
TKPIRMotionSensor::TKPIRMotionSensor(void) : TKPort(0)
{

}

/**
 * Alternate Constructor which can call your own function to map the Motion Sensor device to arduino port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
TKPIRMotionSensor::TKPIRMotionSensor(uint8_t port) : TKPort(port)
{

}
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Motion Sensor device to arduino port
 * \param[in]
 *   ModePin - arduino port for BIS0001's A port
 * \param[in]
 *   SensorPin - arduino port for BIS0001's Vo port
 */
TKPIRMotionSensor::TKPIRMotionSensor(uint8_t ModePin,uint8_t SensorPin)
{
  _ModePin = ModePin;
  _SensorPin = SensorPin;
  pinMode(_ModePin, OUTPUT);
  pinMode(_sensorPin, INPUT);
}
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
void TKPIRMotionSensor::setpin(uint8_t ModePin,uint8_t SensorPin)
{
  _ModePin = ModePin;
  _SensorPin = SensorPin;
  pinMode(_ModePin, OUTPUT);
  pinMode(_SensorPin, INPUT);
#ifdef TK_PORT_DEFINED
  s1 = _ModePin;
  s2 = _SensorPin;
#endif // TK_PORT_DEFINED
}

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
void TKPIRMotionSensor::SetPirMotionMode(uint8_t ModePin)
{
#ifdef TK_PORT_DEFINED
  TKPort::dWrite1(ModePin);
#else // TK_PORT_DEFINED
  digitalWrite(_ModePin, ModePin);
#endif // TK_PORT_DEFINED
}

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
bool TKPIRMotionSensor::isHumanDetected()
{
#ifdef TK_PORT_DEFINED
  return(TKPort::dRead2());
#else // TK_PORT_DEFINED
  return digitalRead(_SensorPin);
#endif // TK_PORT_DEFINED
}

