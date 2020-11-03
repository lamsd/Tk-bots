
#include "TKHumitureSensor.h"

#ifdef TK_PORT_DEFINED
/**
 * Alternate Constructor which can call your own function to map the humiture sensor to arduino port,
 * no pins are used or initialized here.
 * \param[in]
 *   None
 */
TKHumiture::TKHumiture(void) : TKPort(0)
{

}

/**
 * Alternate Constructor which can call your own function to map the temperature sensor to arduino port,
 * the slot2 pin will be used here since specify slot is not be set.
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
TKHumiture::TKHumiture(uint8_t port) : TKPort(port)
{

}
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
TKHumiture::TKHumiture(uint8_t port)
{
  _DataPin = port;
}
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
void TKHumiture::setpin(uint8_t port)
{
  _DataPin = port;
  s2 = _DataPin;
}

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
void TKHumiture::update(void)
{
  uint8_t data[5] = {0};
  unsigned long Time, datatime;
  
#ifdef TK_PORT_DEFINED
  TKPort::dWrite2(HIGH);
  delay(250);

  TKPort::dWrite2(LOW);
  delay(20);

  TKPort::dWrite2(HIGH);
  delayMicroseconds(40);
  TKPort::dWrite2(LOW);

#else // TK_PORT_DEFINED
  pinMode(_DataPin,OUTPUT);
  digitalWrite(_DataPin,HIGH);
  delay(250);

  digitalWrite(_DataPin,LOW);
  delay(20);
  
  digitalWrite(_DataPin,HIGH);
  delayMicroseconds(40);
  digitalWrite(_DataPin,LOW);
#endif // TK_PORT_DEFINED
  delayMicroseconds(10);
  Time = millis();
#ifdef TK_PORT_DEFINED
  while(TKPort::dRead2() != HIGH)
#else // TK_PORT_DEFINED
  pinMode(_DataPin,INPUT_PULLUP);
  while(digitalRead(_DataPin) != HIGH)
#endif // TK_PORT_DEFINED
  {
    if( ( millis() - Time ) > 4)
    {
      Humidity = 0;
      Temperature = 0;
      break;
    }
  }

  Time = millis();
  
#ifdef TK_PORT_DEFINED
  while(TKPort::dRead2() != LOW)
#else // TK_PORT_DEFINED
  pinMode(_DataPin,INPUT_PULLUP);
  while(digitalRead(_DataPin) != LOW)
#endif // TK_PORT_DEFINED
  {
    if( ( millis() - Time ) > 4)
    {
      break;
    }
  }

  for(int16_t i=0;i<40;i++)
  {
  	Time = millis();
#ifdef TK_PORT_DEFINED
    while(TKPort::dRead2() == LOW)
#else // TK_PORT_DEFINED
    pinMode(_DataPin,INPUT_PULLUP);
    while(digitalRead(_DataPin) == LOW)
#endif // TK_PORT_DEFINED
    {
      if( ( millis() - Time ) > 4)
      {
        break;
      }
    }

    datatime = micros();
    Time = millis();
#ifdef TK_PORT_DEFINED
    while(TKPort::dRead2() == HIGH)
#else // TK_PORT_DEFINED
    pinMode(_DataPin,INPUT_PULLUP);
    while(digitalRead(_DataPin) == HIGH)
#endif // TK_PORT_DEFINED
    {
      if( ( millis() - Time ) > 4 )
      {
        break;
      }
    }

    if ( micros() - datatime > 40 )
    {
      data[i/8] <<= 1;
      data[i/8] |= 0x01;
    }
    else
    {
      data[i/8] <<= 1;
    }
  }
   
  if(data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))
  {
  	Humidity = data[0];
    Temperature = data[2];
  }
}

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
uint8_t TKHumiture::getHumidity(void)
{
  return Humidity;
}

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
uint8_t TKHumiture::getTemperature(void)
{
  return Temperature;
}

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
uint8_t TKHumiture::getValue(uint8_t index)
{
  if(index == 0)
  {
    return Humidity;
  }
  else
  {
    return Temperature;
  }
}

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
double TKHumiture::getFahrenheit(void)//Celsius degrees to Fahrenheit
{
  return 1.8 * Temperature + 32;
}


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
double TKHumiture::getKelvin(void)
{
  return Temperature + 273.15;
}

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
double TKHumiture::getdewPoint(void)
{
  double A0= 373.15/(273.15 + Temperature);
  double SUM = -7.90298 * (A0-1);
  SUM += 5.02808 * log10(A0);
  SUM += -1.3816e-7 * (pow(10, (11.344*(1-1/A0)))-1) ;
  SUM += 8.1328e-3 * (pow(10,(-3.49149*(A0-1)))-1) ;
  SUM += log10(1013.246);
  double VP = pow(10, SUM-3) * Humidity;
  double T = log(VP/0.61078);   // temp var
  return (241.88 * T) / (17.558-T);
}

/**
 * \par Function
 *    dewPointFast
 * \par Description
 *    Fast calculating dew point, peed is 5 times to dewPoint().
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
double TKHumiture::getPointFast()
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * Temperature) / (b + Temperature) + log((double)Humidity/100);
  //double Td = (b * temp) / (a - temp);
  return ((b * temp) / (a - temp));
}

