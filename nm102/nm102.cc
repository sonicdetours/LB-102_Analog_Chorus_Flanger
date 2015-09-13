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
// NM-102 main program
//
#include "avrlib/gpio.h"
#include "avrlib/boot.h"
#include "avrlib/time.h"

#include "lfo.h"
#include "timer.h"

using namespace avrlib;
using namespace nm102;

NumberedGpio<13> led;
Lfo lfo;

TIMER_0_TICK {
  TickSystemClock();
}

int main(void) {
  Boot(true);
  lfo.Update();
  led.set_mode(DIGITAL_OUTPUT);
  while (1) {
    led.High();
    Delay(250);
    led.Low();
    Delay(250);
  }
}
