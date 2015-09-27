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
#include <avr/io.h>
#include <util/delay.h>

#include "avrlib/gpio.h"
#include "avrlib/boot.h"
#include "avrlib/time.h"

#include "lfo.h"
#include "delay_clock.h"

using namespace avrlib;
using namespace nm102;

Lfo lfo;

DelayClock<2, 3, OCR2ARegister, OCR2BRegister> leftDelayClock;
DelayClock<0, 5, OCR0ARegister, OCR0BRegister> rightDelayClock;

TIMER_1_TICK {
  lfo.Update();
  leftDelayClock.set_frequency(200000);
  rightDelayClock.set_frequency(200000);
}


void Init() {

  // Start Timer1 at 1220.7 Hz for the main program loop
  Timer<1>::set_mode (TIMER_NORMAL);
  Timer<1>::set_prescaler(3);
  Timer<1>::Start();

  lfo.Reset(1221, 8, LFO_TRIANGLE);

  leftDelayClock.Init();
  rightDelayClock.Init();
}

int main(void) {
  Boot(false);
  Init();
  while (1) { }
}