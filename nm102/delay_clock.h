// Copyright (c) 2015 Sonic Detours. All Rights Reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// -----------------------------------------------------------------------------
//
// Delay clock.
//
#ifndef NM102_DELAY_CLOCK_H_
#define NM102_DELAY_CLOCK_H_

#include "avrlib/base.h"
#include "avrlib/gpio.h"

namespace nm102 {


class DelayClock {
 public:
  DelayClock() {}

  void Init() {

    // http://withinspecifications.30ohm.com/2014/02/20/Fast-PWM-on-AtMega328/
    DDRD = 1 << PD3;
    TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(WGM22);

    set_frequency(200000);
  }

  // Set desired output clock frequency for MN3102 (10-200 kHz)
  void set_frequency(uint32_t frequency) {
      uint16_t top = 10000000 / frequency - 1;

      if (top > 255) {
        set_prescaler(2);
        top = top >> 3;
      } else {
        set_prescaler(1);
      }

      set_top(top);        
  }

 private:

  void set_top(uint8_t value) {
    OCR2A = value;
    OCR2B = value >> 1;
  }

  void set_prescaler(uint8_t value) {
    switch(value) {
      case 2 : // 8
        TCCR2B = _BV(WGM22) | (1 << CS21);
        break;
      case 1 : // 1
      default :
        TCCR2B = _BV(WGM22) | (1 << CS20);
    }
  }

  DISALLOW_COPY_AND_ASSIGN(DelayClock);
};

}  // namespace nm102

#endif