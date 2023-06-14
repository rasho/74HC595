#include "ShiftRegister74HC595.h"

ShiftRegisterMulti::ShiftRegisterMulti(int dataPin, int latchPin, int clockPin, int numRegisters, int numPinsPerRegister) {
  _dataPin = dataPin;
  _latchPin = latchPin;
  _clockPin = clockPin;
  _numRegisters = numRegisters;
  _numPinsPerRegister = numPinsPerRegister;
  _registerStates = new byte[numRegisters];
  _registerModes = new byte[numRegisters];
  _outputHoldTime = 0;
  _clockDivision = 1;
}

void ShiftRegisterMulti::begin() {
  pinMode(_dataPin, OUTPUT);
  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
}

void ShiftRegisterMulti::setOutput(int registerIndex, int pinIndex, bool state) {
  if (registerIndex >= 0 && registerIndex < _numRegisters && isValidPinIndex(pinIndex)) {
    bitWrite(_registerStates[registerIndex], _numPinsPerRegister - pinIndex - 1, state);
  }
}

void ShiftRegisterMulti::setAllOutputs(bool state) {
  for (int i = 0; i < _numRegisters; i++) {
    _registerStates[i] = state ? 0xFF : 0x00;
  }
}

void ShiftRegisterMulti::setAllOutputsLow() {
  setAllOutputs(false);
}

void ShiftRegisterMulti::setAllOutputsHigh() {
  setAllOutputs(true);
}

void ShiftRegisterMulti::setClockFrequency(unsigned long frequency) {
  unsigned long period = 1000000 / (frequency * _clockDivision);
  digitalWrite(_clockPin, LOW);
  delayMicroseconds(period / 2);
  digitalWrite(_clockPin, HIGH);
  delayMicroseconds(period / 2);
}

bool ShiftRegisterMulti::getInputState(int registerIndex, int pinIndex) {
  if (registerIndex >= 0 && registerIndex < _numRegisters && isValidPinIndex(pinIndex)) {
    byte registerValue = _registerStates[registerIndex];
    return bitRead(registerValue, _numPinsPerRegister - pinIndex - 1);
  }
  return false;
}

void ShiftRegisterMulti::updateRegisters() {
  digitalWrite(_latchPin, LOW);
  for (int i = _numRegisters - 1; i >= 0; i--) {
    shiftOut(_dataPin, _clockPin, LSBFIRST, _registerStates[i]);
  }
  digitalWrite(_latchPin, HIGH);
  delayMicroseconds(_outputHoldTime);
}

void ShiftRegisterMulti::setPinMode(int registerIndex, int pinIndex, int pinMode) {
  if (registerIndex >= 0 && registerIndex < _numRegisters && isValidPinIndex(pinIndex)) {
    bitWrite(_registerModes[registerIndex], _numPinsPerRegister - pinIndex - 1, pinMode);
  }
}

int ShiftRegisterMulti::getPinMode(int registerIndex, int pinIndex) {
  if (registerIndex >= 0 && registerIndex < _numRegisters && isValidPinIndex(pinIndex)) {
    return bitRead(_registerModes[registerIndex], _numPinsPerRegister - pinIndex - 1);
  }
  return -1;
}

void ShiftRegisterMulti::setOutputHoldTime(int holdTime) {
  _outputHoldTime = holdTime;
}

int ShiftRegisterMulti::getOutputHoldTime() {
  return _outputHoldTime;
}

void ShiftRegisterMulti::readInputStates(bool* inputStates) {
  for (int i = 0; i < _numRegisters; i++) {
    byte registerValue = _registerStates[i];
    for (int j = 0; j < _numPinsPerRegister; j++) {
      int pinIndex = _numPinsPerRegister - j - 1;
      inputStates[i * _numPinsPerRegister + j] = bitRead(registerValue, pinIndex);
    }
  }
}

void ShiftRegisterMulti::setClockDivision(int clockDivision) {
  _clockDivision = clockDivision;
}

int ShiftRegisterMulti::getClockDivision() {
  return _clockDivision;
}

bool ShiftRegisterMulti::isValidPinIndex(int pinIndex) {
  return pinIndex >= 0 && pinIndex < _numPinsPerRegister;
}
