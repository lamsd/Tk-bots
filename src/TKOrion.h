
#ifndef TKOrion_H
#define TKOrion_H

#include <Arduino.h>
#include "TKConfig.h"

// Supported Modules drive needs to be added here
#include "TK7SegmentDisplay.h"
#include "TKUltrasonicSensor.h"
#include "TKDCMotor.h"
#include "TKRGBLed.h"
#include "TK4Button.h"
#include "TKPotentiometer.h"
#include "TKJoystick.h"
#include "TKPIRMotionSensor.h"
#include "TKShutter.h"
#include "TKLineFollower.h"
#include "TKSoundSensor.h"
#include "TKLimitSwitch.h"
#include "TKLightSensor.h"
#include "TKSerial.h"
#include "TKBluetooth.h"
#include "TKWifi.h"
#include "TKTemperature.h"
#include "TKGyro.h"
#include "TKInfraredReceiver.h"
#include "TKCompass.h"
#include "TKUSBHost.h"
#include "TKTouchSensor.h"
#include "TKStepper.h"
#include "TKEncoderMotor.h"
#include "TKEncoderNew.h"
#include "TKBuzzer.h"
#include "TKLEDMatrix.h"
#include "TKHumitureSensor.h"
#include "TKFlameSensor.h"
#include "TKGasSensor.h"
#include "TKColorSensor.h"

/*********************  Orion Board GPIO Map *********************************/
// struct defined in TKPort.h
TKPort_Sig mePort[17] =
{
  { NC, NC }, { A6, A7 }, { A0, A1 }, { A2, A3 }, { NC, NC },
  { 12, 13 }, { 10, 11 }, { 8, 9 }, { 2, 7 }, { 6, 3 },
  { 5, 4 }, { NC, NC }, { NC, NC }, { NC, NC }, { NC, NC },
  { NC, NC },{ NC, NC },
};

#define buzzerOn()  pinMode(SCL,OUTPUT),digitalWrite(SCL, HIGH)
#define buzzerOff() pinMode(SCL,OUTPUT),digitalWrite(SCL, LOW)

#endif // TKOrion_H
