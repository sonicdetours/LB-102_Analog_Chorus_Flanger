#include <PWM.h>
#include <TimerOne.h>
#include "Lfo.h"

int32_t update_frequency = 1000; // Hz
int32_t delayAmount = 10000; // in us

Lfo lfo = Lfo(update_frequency);

int clockPin = 3;
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);    

  Timer1.initialize(update_frequency);
  Timer1.attachInterrupt(interrupt); // blinkLED to run every 0.15 seconds

  Timer2_Initialize(); // associated with pin 3

  lfo.set_rate(2000);
  lfo.set_depth(5000);
}

void loop() {
}

void interrupt() {
  lfo.Update();
  setClockFrequency(); 
}

void setClockFrequency() {
  bool success = SetPinFrequency(clockPin, getClockHz());
  
  if(!success) {
    digitalWrite(ledPin, LOW);    
  }
  
  pwmWrite(clockPin, 127); // 50% duty cycle
}

int32_t getClockHz() {
  return 512000000 / (delayAmount + lfo.value());  // ratio according to datasheet
}
