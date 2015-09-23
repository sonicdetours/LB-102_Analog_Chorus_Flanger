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

#include "Lfo.h"

using namespace avrlib;
using namespace nm102;

NumberedGpio<9> lfoPin;
Lfo lfo;


TIMER_0_TICK {
  lfo.Update();
  lfoPin.set_pwm_value(lfo.Render());
}

void Init() {
  // Set Timer1 to 4.901 kHz for nice smooth PWM
  Timer<1>::set_mode(TIMER_PWM_PHASE_CORRECT);
  Timer<1>::set_prescaler(2); 

  lfoPin.set_mode(PWM_OUTPUT);

  lfo.Reset(1221, 8, LFO_RAMP_DOWN);

  // Start Timer0 at 1220.7 Hz for the main program loop
  Timer<0>::set_mode (TIMER_NORMAL);
  Timer<0>::set_prescaler(3);
  Timer<0>::Start();
}

int main(void) {
  Boot(true);
  Init();
  while (1) { }
}