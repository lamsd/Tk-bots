
#include "TKInfraredReceiver.h"

#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the Infrared Receiver to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
TKInfraredReceiver::TKInfraredReceiver(void) : TKSerial(0)
{
}

/**
 * Alternate Constructor which can call your own function to map the Infrared Receiver to arduino port,
 * If the hardware serial was selected, we will used the hardware serial.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
TKInfraredReceiver::TKInfraredReceiver(uint8_t port) : TKSerial(port)
{
  _RxPin = s2;
  _KeyCheckPin = s1;
}
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
TKInfraredReceiver::TKInfraredReceiver(uint8_t receivePin, uint8_t keycheckpin, bool inverse_logic)\
                        : TKSerial(receivePin, transmitPin, inverse_logic)
{
  _RxPin = receivePin;
  _KeyCheckPin = keycheckpin;
}
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
void TKInfraredReceiver::begin(void)
{
  TKSerial::begin(9600);
#ifdef TK_PORT_DEFINED
  pinMode(s1, INPUT);
#else // TK_PORT_DEFINED
  pinMode(_KeyCheckPin, INPUT);
#endif // TK_PORT_DEFINED
}

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
int16_t TKInfraredReceiver::read(void)
{
  int16_t val;
  uint16_t i;
  val = TKSerial::read();     /* Read serial infrared data */
  val &= 0xff;
  return(val);
}

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
bool TKInfraredReceiver::buttonState(void)
{
  bool val;
  if(_hard)
  {
    TKSerial::end();
  }
#ifdef TK_PORT_DEFINED
  val = TKPort::dRead1();
#else // TK_PORT_DEFINED
  val =  digitalRead(_KeyCheckPin);
#endif // TK_PORT_DEFINED
  if(_hard)
  {
    begin();
  }
  return(!val);
}

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
uint8_t TKInfraredReceiver::getCode(void)
{
  return _irCode;
}

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
void TKInfraredReceiver::loop(void)
{
  if(buttonState() == 1)
  {
    if(TKSerial::available() > 0)
    {
      int r = read();
      if(r<0xff)
      {
        if(r == 0)
        {
          _irCode = _preIrCode;
        }
        else
        {
          _irCode = r;
          _preIrCode = _irCode;
        }
      }
    }
  }
  else
  {
    _irCode = 0;
    _preIrCode = 0;
  }
}

