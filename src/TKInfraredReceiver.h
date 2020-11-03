

#ifndef TKInfraredReceiver_H
#define TKInfraredReceiver_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include "TKConfig.h"
#include "TKSerial.h"

/* NEC Code table */
#define IR_BUTTON_POWER     (0x45)
#define IR_BUTTON_A         (0x45)
#define IR_BUTTON_B         (0x46)
#define IR_BUTTON_MENU      (0x47)
#define IR_BUTTON_C         (0x47)
#define IR_BUTTON_TEST      (0x44)
#define IR_BUTTON_D         (0x44)
#define IR_BUTTON_PLUS      (0x40)
#define IR_BUTTON_UP        (0x40)
#define IR_BUTTON_RETURN    (0x43)
#define IR_BUTTON_E         (0x43)
#define IR_BUTTON_PREVIOUS  (0x07)
#define IR_BUTTON_LEFT      (0x07)
#define IR_BUTTON_PLAY      (0x15)
#define IR_BUTTON_SETTING   (0x15)
#define IR_BUTTON_NEXT      (0x09)
#define IR_BUTTON_RIGHT     (0x09)
#define IR_BUTTON_MINUS     (0x19)
#define IR_BUTTON_DOWN      (0x19)
#define IR_BUTTON_CLR       (0x0D)
#define IR_BUTTON_F     (0x0D)
#define IR_BUTTON_0     (0x16)
#define IR_BUTTON_1     (0x0C)
#define IR_BUTTON_2     (0x18)
#define IR_BUTTON_3     (0x5E)
#define IR_BUTTON_4     (0x08)
#define IR_BUTTON_5     (0x1C)
#define IR_BUTTON_6     (0x5A)
#define IR_BUTTON_7     (0x42)
#define IR_BUTTON_8     (0x52)
#define IR_BUTTON_9     (0x4A)

#ifdef TK_PORT_DEFINED
#include "TKPort.h"
#endif /* TK_PORT_DEFINED */

/**
 * Class: TKInfraredReceiver
 * \par Description
 * Declaration of Class TKInfraredReceiver
 */
#ifndef TK_PORT_DEFINED
class TKInfraredReceiver
#else // !TK_PORT_DEFINED
class TKInfraredReceiver : public TKSerial
#endif // !TK_PORT_DEFINED
{
public:
#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Infrared Receiver to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
  TKInfraredReceiver(void);

/**
 * Alternate Constructor which can call your own function to map the Infrared Receiver to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  TKInfraredReceiver(uint8_t port);
#else // TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Infrared Receiver to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   receivePin - the rx pin of serial(arduino port)
 * \param[in]
 *   keycheckpin - the pin used for check the pin pressed state(arduino port)
 * \param[in]
 *   inverse_logic - Whether the Serial level need inv.
 */
  TKInfraredReceiver(uint8_t receivePin, uint8_t transmitPin, bool inverse_logic);
#endif // TK_PORT_DEFINED

/**
 * \par Function
 *   begin
 * \par Description
 *   Sets the speed (baud rate) for the serial communication. Supported baud 
 *   rates is 9600bps
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void begin(void);

/**
 * \par Function
 *   read
 * \par Description
 *   Return a character that was received on the RX pin of the software serial port. 
 *   Note that only one SoftwareSerial instance can receive incoming data at a time 
 *  (select which one with the listen() function).
 * \par Output
 *   None
 * \return
 *   The character read, or -1 if none is available
 * \par Others
 *   None
 */
  int read();

/**
 * \par Function
 *   buttonState
 * \par Description
 *   Check button press state
 * \par Output
 *   None
 * \return
 *   true: The button is pressed, false: No button is pressed
 * \par Others
 *   None
 */
  bool buttonState(void);

/**
 * \par Function
 *   getCode
 * \par Description
 *   Get the button code
 * \par Output
 *   None
 * \return
 *   Return the button code
 * \par Others
 *   None
 */
  uint8_t getCode(void);

/**
 * \par Function
 *   loop
 * \par Description
 *   This function used with getCode, it should called in the main loop
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   This function used with getCode
 */
  void loop(void);
private:
  volatile uint8_t _RxPin;
  volatile uint8_t _KeyCheckPin;
  uint8_t _irCode;
  uint8_t _preIrCode;
};

#endif

