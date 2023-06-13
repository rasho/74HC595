#ifndef ShiftRegister74HC595_h
#define ShiftRegister74HC595_h

#include <Arduino.h>

class ShiftRegister74HC595 {
  private:
    int dataPin;
    int latchPin;
    int clockPin;
    int numRegisters;
    byte* registers;

  public:
    ShiftRegister74HC595(int data, int latch, int clock, int num);
    void setOutput(int pin, bool value);
    void setOutput(int registerIndex, int pin, bool value);
    void updateRegisters();
    void clearRegisters();
    void shiftLeft();
    void shiftRight();
    void blinkEffect(int registerIndex, int pin, int interval);
    void fadeEffect(int registerIndex, int pin, int duration);
    void pulseEffect(int registerIndex, int pin, int duration);
    void randomBlinkEffect(int registerIndex, int pin, int interval);
    void waveEffect(int duration, int interval);
    void fadingTrailEffect(int duration, int interval);
    void sparkleEffect(int numPins, int duration, int interval);
    void runningLightsEffect(int direction, int speed);
};

#endif
