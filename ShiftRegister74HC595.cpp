#include "ShiftRegister74HC595.h"

ShiftRegister74HC595::ShiftRegister74HC595(int data, int latch, int clock, int num) {
  dataPin = data;
  latchPin = latch;
  clockPin = clock;
  numRegisters = num;
  
  registers = new byte[numRegisters];
  
  for (int i = 0; i < numRegisters; i++) {
    registers[i] = 0;
  }
  
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void ShiftRegister74HC595::setOutput(int pin, bool value) {
  for (int i = 0; i < numRegisters; i++) {
    setOutput(i, pin, value);
  }
}

void ShiftRegister74HC595::setOutput(int registerIndex, int pin, bool value) {
  if (registerIndex >= 0 && registerIndex < numRegisters && pin >= 0 && pin < 8) {
    byte bitmask = 1 << pin;
    
    if (value) {
      registers[registerIndex] |= bitmask;
    } else {
      registers[registerIndex] &= ~bitmask;
    }
  }
}

void ShiftRegister74HC595::updateRegisters() {
  for (int i = numRegisters - 1; i >= 0; i--) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, registers[i]);
    digitalWrite(latchPin, HIGH);
  }
}

void ShiftRegister74HC595::clearRegisters() {
  for (int i = 0; i < numRegisters; i++) {
    registers[i] = 0;
  }
  
  updateRegisters();
}

void ShiftRegister74HC595::shiftLeft() {
  for (int i = 0; i < numRegisters; i++) {
    registers[i] <<= 1;
  }
  
  updateRegisters();
}

void ShiftRegister74HC595::shiftRight() {
  for (int i = 0; i < numRegisters; i++) {
    registers[i] >>= 1;
  }
  
  updateRegisters();
}

void ShiftRegister74HC595::blinkEffect(int registerIndex, int pin, int interval) {
  setOutput(registerIndex, pin, HIGH);
  updateRegisters();
  delay(interval);
  setOutput(registerIndex, pin, LOW);
  updateRegisters();
  delay(interval);
}

void ShiftRegister74HC595::fadeEffect(int registerIndex, int pin, int duration) {
  int steps = 255;  // Broj koraka za postepeno povećanje i smanjenje jačine svetlosti
  int delayTime = duration / steps;
  
  for (int i = 0; i <= steps; i++) {
    int brightness = map(i, 0, steps, 0, 255);
    setOutput(registerIndex, pin, brightness);
    updateRegisters();
    delay(delayTime);
  }
  
  for (int i = steps; i >= 0; i--) {
    int brightness = map(i, 0, steps, 0, 255);
    setOutput(registerIndex, pin, brightness);
    updateRegisters();
    delay(delayTime);
  }
}

void ShiftRegister74HC595::pulseEffect(int registerIndex, int pin, int duration) {
  int steps = 100;  // Broj koraka za pulsiranje
  int delayTime = duration / (steps * 2);
  
  for (int i = 0; i <= steps; i++) {
    int brightness = map(i, 0, steps, 0, 255);
    setOutput(registerIndex, pin, brightness);
    updateRegisters();
    delay(delayTime);
  }
  
  for (int i = steps; i >= 0; i--) {
    int brightness = map(i, 0, steps, 0, 255);
    setOutput(registerIndex, pin, brightness);
    updateRegisters();
    delay(delayTime);
  }
}

void ShiftRegister74HC595::randomBlinkEffect(int registerIndex, int pin, int interval) {
  for (int i = 0; i < 10; i++) {
    setOutput(registerIndex, pin, HIGH);
    updateRegisters();
    delay(interval);
    setOutput(registerIndex, pin, LOW);
    updateRegisters();
    delay(interval);
  }
}

void ShiftRegister74HC595::waveEffect(int duration, int interval) {
  int numPins = numRegisters * 8;
  for (int i = 0; i < numPins; i++) {
    setOutput(i / 8, i % 8, HIGH);
    updateRegisters();
    delay(interval);
    setOutput(i / 8, i % 8, LOW);
  }
  for (int i = numPins - 1; i >= 0; i--) {
    setOutput(i / 8, i % 8, HIGH);
    updateRegisters();
    delay(interval);
    setOutput(i / 8, i % 8, LOW);
  }
  delay(duration);
}

void ShiftRegister74HC595::fadingTrailEffect(int duration, int interval) {
  int numPins = numRegisters * 8;
  for (int i = 0; i < numPins; i++) {
    setOutput(i / 8, i % 8, HIGH);
    updateRegisters();
    delay(interval);
  }
  for (int i = numPins - 1; i >= 0; i--) {
    setOutput(i / 8, i % 8, LOW);
    updateRegisters();
    delay(interval);
  }
  delay(duration);
}

void ShiftRegister74HC595::sparkleEffect(int numPins, int duration, int interval) {
  for (int i = 0; i < numPins; i++) {
    setOutput(i / 8, i % 8, HIGH);
  }
  updateRegisters();
  
  for (int i = 0; i < numPins; i++) {
    if (random(0, 100) < 50) {
      setOutput(i / 8, i % 8, LOW);
    }
  }
  updateRegisters();
  
  delay(duration);
  
  clearRegisters();
  updateRegisters();
}

void ShiftRegister74HC595::runningLightsEffect(int direction, int speed) {
  int numPins = numRegisters * 8;
  int currentIndex = 0;
  
  while (true) {
    setOutput(currentIndex / 8, currentIndex % 8, HIGH);
    updateRegisters();
    delay(speed);
    setOutput(currentIndex / 8, currentIndex % 8, LOW);
    
    currentIndex += direction;
    if (currentIndex < 0) {
      currentIndex = numPins - 1;
    } else if (currentIndex >= numPins) {
      currentIndex = 0;
    }
  }
}
