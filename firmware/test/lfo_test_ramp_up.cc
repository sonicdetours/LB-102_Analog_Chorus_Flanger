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

#include "gtest/gtest.h"
#include "lfo_test.h"
#include "nm-102/lfo.h"

// 255 -                *  
//                    * 
//                  *  
//                *       
//              *  
//            * 
//          *  
//   0 -  *
//        ---------------
//        ^ . . . ^ . . .          

TEST_F(LfoTest, ramp_up_starts_low) {
  lfo.set_sample_rate(2);
  lfo.set_rate(8);
  lfo.set_shape(LFO_RAMP_UP);
  
  EXPECT_EQ(0, lfo.Render());
}

// 255 -                *  
//                    * 
//                  *  
//                *       
//              *  
//            * 
//          *  
//   0 -  *
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, ramp_up_increases_linearly) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);
  lfo.set_shape(LFO_RAMP_UP);

  lfo.Update();
  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(192, lfo.Render());
}

// 255 -                *  
//                    * 
//                  *  
//                *       
//              *  
//            * 
//          *  
//   0 -  *
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, ramp_up_goes_low_on_new_cycle) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);
  lfo.set_shape(LFO_RAMP_UP);

  lfo.Update();
  lfo.Update();
  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(0, lfo.Render());
}
