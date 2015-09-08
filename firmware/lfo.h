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
// A basic LFO.
//
#ifndef LFO_H_
#define LFO_H_

#include "base.h"

enum LfoShape {
  LFO_SQUARE_WAVE,
  LFO_RAMP_DOWN,
  LFO_RAMP_UP,
  LFO_TRIANGLE,
  LFO_RANDOM,
  LFO_SMOOTH_RANDOM,
  LFO_SAMPLE_AND_HOLD
};


class Lfo {
 public:

  Lfo(uint16_t sample_rate = 1) : sample_rate_(sample_rate), shape_(LFO_SQUARE_WAVE), phase_(0) { 
    set_rate(8);
  }

  void Update() {
    phase_ += phase_increment_;
  } 

  uint8_t Render() {
    switch (shape_) {

      case LFO_RAMP_DOWN:
        return 255 - (phase_ >> 8);

      case LFO_RAMP_UP:
        return phase_ >> 8;

      case LFO_TRIANGLE:
        return (phase_ < 32767) ? ~static_cast<uint8_t>(phase_ >> 7) : phase_ >> 7;

      case LFO_SQUARE_WAVE:
      default:
        return (phase_ < 32767) ? 255 : 0;
    }
  }

  void Reset(uint16_t sample_rate, uint8_t rate, uint8_t shape = LFO_SQUARE_WAVE) {
    set_sample_rate(sample_rate);
    set_rate(rate);    
    set_shape(shape);
    phase_ = 0;
  }

  void reset_phase() {
    phase_ = 0;
  }

  void set_sample_rate(uint16_t sample_rate) {
    sample_rate_ = sample_rate;
    set_rate(rate_);
  }

  void set_shape(uint8_t shape) {
    shape_ = shape;
  }

  // Set rate in 1/8 hz
  void set_rate(uint8_t rate) {
    rate_ = rate;
    phase_increment_ = (65536 * (rate_ / 8)) / sample_rate_;
  }

 private:
  uint16_t sample_rate_;
  uint8_t rate_;
  uint8_t shape_;
  uint16_t phase_;
  uint16_t phase_increment_;

  DISALLOW_COPY_AND_ASSIGN(Lfo);
};

#endif
