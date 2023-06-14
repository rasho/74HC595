#ifndef ShiftRegisterMulti_h
#define ShiftRegisterMulti_h

#include <Arduino.h>

class ShiftRegisterMulti {
public:
  ShiftRegisterMulti(int dataPin, int latchPin, int clockPin, int numRegisters, int numPinsPerRegister);
  void begin();
  void setOutput(int registerIndex, int pinIndex, bool state);
  void setAllOutputs(bool state);
  void setAllOutputsLow();
  void setAllOutputsHigh();
  void setClockFrequency(unsigned long frequency);
  bool getInputState(int registerIndex, int pinIndex);
  void updateRegisters();
  void setPinMode(int registerIndex, int pinIndex, int pinMode);
  int getPinMode(int registerIndex, int pinIndex);
  void setOutputHoldTime(int holdTime);
  int getOutputHoldTime();
  void readInputStates(bool* inputStates);
  void setClockDivision(int clockDivision);
  int getClockDivision();

private:
  int _dataPin;
  int _latchPin;
  int _clockPin;
  int _numRegisters;
  int _numPinsPerRegister;
  byte* _registerStates;
  byte* _registerModes;
  unsigned long _outputHoldTime;
  int _clockDivision;
  bool isValidPinIndex(int pinIndex);
};

#endif
