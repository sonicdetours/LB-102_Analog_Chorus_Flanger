#include "gtest/gtest.h"
#include "lfo_test.h"
#include "../lfo.h"

    
// 255 -  * * * *       *
//              *       *
//              *       *
//   0 -        * * * * *
//        ---------------
//        ^ . . . ^ . . .          

TEST_F(LfoTest, square_wave_starts_high) {
  lfo.set_sample_rate(2);
  lfo.set_rate(8);
  
  EXPECT_EQ(255, lfo.Render());
}

// 255 -  * * * *       *
//              *       *
//              *       *
//   0 -        * * * * *
//        ---------------
//        ^ . . . ^ . . .          

TEST_F(LfoTest, square_wave_goes_low_at_half_cycle) {
  lfo.set_sample_rate(2);
  lfo.set_rate(8);

  lfo.Update();
  
  EXPECT_EQ(0, lfo.Render());
}

// 255 -  * * * *       *
//              *       *
//              *       *
//   0 -        * * * * *
//        ---------------
//        ^ . . . ^ . . .          

TEST_F(LfoTest, square_wave_goes_high_on_new_cycle) {
  lfo.set_sample_rate(2);
  lfo.set_rate(8);

  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(255, lfo.Render());
}

// 255 -  * * * *       *
//              *       *
//              *       *
//   0 -        * * * * *
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, higher_sample_rate_increases_resolution) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);

  lfo.Update();
  
  EXPECT_EQ(255, lfo.Render());
}

// 255 -  * * * *       *
//              *       *
//              *       *
//   0 -        * * * * *
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, higher_sample_rate_still_goes_low) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);

  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(0, lfo.Render());
}

// 255 -  * *   * * *   *
//          *   *   *   *
//          *   *   *   *
//   0 -    * * *   * * * 
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, higher_lfo_rate_increases_speed) {
  lfo.set_sample_rate(4);
  lfo.set_rate(16);

  lfo.Update();
  
  EXPECT_EQ(0, lfo.Render());
}
