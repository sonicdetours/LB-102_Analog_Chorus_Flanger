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
// Timer calculations for BBD clock.
//
#ifndef NM102_TIMER_H_
#define NM102_TIMER_H_

enum TimerPrescaler {
  Prescaler_8,
  Prescaler_64,
  Prescaler_256
};

#include "avrlib/base.h"

namespace nm102 {

// Assuming 20 MHz clock speed

class Timer {
 public:
  Timer() : prescaler_(Prescaler_8), compare_(45)
  { }

  // Set delay time (0-1023)
  void set_delay(uint16_t delay) {
    // 8-bit timer has only 558 "steps" in the range that will produce 0.4-50 ms delay
    delay = (delay * 558) >> 10; 

    if (delay < 179) {
      prescaler_ = Prescaler_8;
      compare_ = 45 + delay;
    } else if (delay < 370) {
      prescaler_ = Prescaler_64;
      compare_ = delay - 178;
    } else {
      prescaler_ = Prescaler_256;
      compare_ = delay - 369;
    }
  }

  uint8_t prescaler() {
    return prescaler_;
  }

  uint8_t compare() {
    return compare_;
  }

 private:
  uint8_t prescaler_;
  uint8_t compare_;
};

} // namespace nm102

#endif
