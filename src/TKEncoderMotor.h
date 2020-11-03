

#ifndef TKEncoderMotor_h
#define TKEncoderMotor_h

#include <stdbool.h>
#include "TKConfig.h"
#include "TKPort.h"

///@brief Class for Encoder Motor Driver
class TKEncoderMotor: public TKPort{
public:
/**
 * Alternate Constructor which can call your own function to map the Encoder Motor to arduino port,
 * you can set any slot for the Encoder Motor device. 
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 */
  TKEncoderMotor(uint8_t addr,uint8_t slot);

/**
 * Alternate Constructor which can call your own function to map the Encoder Motor to arduino port,
 * you can set any slot for the Encoder Motor device.
 * \param[in]
 *   slot - SLOT1 or SLOT2
 */
  TKEncoderMotor(uint8_t slot);

/**
 * Alternate Constructor which can call your own function to map the Encoder Motor to arduino port,
 * you should initialized slot and slaveAddress here for the Encoder Motor device.
 * \param[in]
 *   None
 */
  TKEncoderMotor();

/**
 * \par Function
 *    begin
 * \par Description
 *    Initialize Encoder Motor.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  void begin();

/**
 * \par Function
 *   reset
 * \par Description
 *   Reset the available data for Encoder Motor.
 * \param[in]
 *   None
 * \par Output
 *   None 
 * \return
 *   None
 * \par Others
 *   None
 */
  boolean reset();

/**
 * \par Function
 *    move
 * \par Description
 *    Motor move.
 * \param[in]
 *    angle - The angle move of Motor.
 * \param[in]
 *    speed - The speed move of Motor.
 * \par Output
 *    None
 * \par Return
 *    Return the result of Motor's movement.
 * \par Others
 *    None
 */
  boolean move(float angle, float speed);

/**
 * \par Function
 *    moveTo
 * \par Description
 *    Motor move to the aim.
 * \param[in]
 *    angle - The angle move of Motor.
 * \param[in]
 *    speed - The speed move of Motor.
 * \par Output
 *    None
 * \par Return
 *    Return the result of Motor's movement to the aim.
 * \par Others
 *    None
 */
  boolean moveTo(float angle, float speed);

/**
 * \par Function
 *    runTurns
 * \par Description
 *    Motor move turns.
 * \param[in]
 *    turns - The turns move of Motor.
 * \param[in]
 *    speed - The speed move of Motor.
 * \par Output
 *    None
 * \par Return
 *    Return the result of Motor's movement.
 * \par Others
 *    None
 */
  boolean runTurns(float turns, float speed);

/**
 * \par Function
 *    runSpeed
 * \par Description
 *    The speed of Motor's movement.
 * \param[in]
 *    speed - The speed move of Motor.
 * \par Output
 *    None
 * \par Return
 *    Return 0.
 * \par Others
 *    None
 */
  boolean runSpeed(float speed);

/**
 * \par Function
 *    runSpeedAndTime
 * \par Description
 *    The speed and time of Motor's movement.
 * \param[in]
 *    speed - The speed move of Motor.
 * \param[in]
 *    time - The time move of Motor.
 * \par Output
 *    None
 * \par Return
 *    Return the result of Motor's movement.
 * \par Others
 *    None
 */
  boolean runSpeedAndTime(float speed, float time);

/**
 * \par Function
 *    getCurrentSpeed
 * \par Description
 *    The current speed of Motor's movement.
 * \param[in]
      None
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  float getCurrentSpeed();

/**
 * \par Function
 *    getCurrentPosition
 * \par Description
 *    The current position of Motor.
 * \param[in]
 *    None
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  float getCurrentPosition();

private:
/**
 * \par Function
 *    request
 * \par Description
 *    The request of Motor.
 * \param[in]
 *    writeData - Write data to Encoder Motor.
  * \param[in]
 *    readData - Read data from Encoder Motor.
  * \param[in]
 *    wlen - The data's length that write to Encoder Motor.
  * \param[in]
 *    rlen - The data's length that read from Encoder Motor.
 * \par Output
 *    None
 * \par Return
 *    None
 * \par Others
 *    None
 */
  void request(byte *writeData, byte *readData, int wlen, int rlen);

  uint8_t _slot;    
  uint8_t _slaveAddress;
  unsigned long _lastTime;
};
#endif
