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
#include "avrlib/gpio.h"

using namespace avrlib;

namespace nm102 {

template<int timerNumber, int pinNumber, typename CompareRegisterA, typename CompareRegisterB>
class DelayClock {

 public:
  DelayClock() {}

  void Init() {
    clockPin.set_mode(DIGITAL_OUTPUT);

    timer.set_mode(
      _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20),
      _BV(WGM22),
      _BV(CS20)
    );

    set_frequency(200000);
  }

  // Set desired output clock frequency for MN3102 (10-200 kHz)
  void set_frequency(uint32_t frequency) {
      uint16_t value = 10000000 / frequency - 1;

      if (value > 255) {
        timer.set_prescaler(2);
        value = value >> 3;
      } else {
        timer.set_prescaler(1);
      }

      compareRegisterA = value;
      compareRegisterB = value >> 1;
  }

 private:

  NumberedGpio<pinNumber> clockPin;
  Timer<timerNumber> timer;

  CompareRegisterA compareRegisterA;
  CompareRegisterB compareRegisterB;

  DISALLOW_COPY_AND_ASSIGN(DelayClock);
};

}  // namespace nm102

#endif