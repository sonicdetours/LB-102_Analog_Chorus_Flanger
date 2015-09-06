#include "gtest/gtest.h"
#include "lfo_test.h"
#include "../lfo.h"

// 255 -  *                      
//          *           *
//     -      *       *   
//              *   *      
//   0 -          *           
//        ^ . . . ^ . . .          

TEST_F(LfoTest, triangle_starts_high) {
  lfo.set_sample_rate(2);
  lfo.set_rate(8);
  lfo.set_shape(LFO_TRIANGLE);
  
  EXPECT_EQ(255, lfo.Render());
}

// 255 -  *                      
//          *           *
//     -      *       *   
//              *   *      
//   0 -          *           
//        ^ ^ ^ ^ ^ ^ ^ ^          

TEST_F(LfoTest, triangle_decreases_linearly) {
  lfo.set_sample_rate(8);
  lfo.set_rate(8);
  lfo.set_shape(LFO_TRIANGLE);

  lfo.Update();
  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(63, lfo.Render());
}

// 255 -  *                      
//          *           *
//     -      *       *   
//              *   *      
//   0 -          *           
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, triangle_is_low_mid_cycle) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);
  lfo.set_shape(LFO_TRIANGLE);

  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(0, lfo.Render());
}

// 255 -  *                      
//          *           *
//     -      *       *   
//              *   *      
//   0 -          *           
//        ^ ^ ^ ^ ^ ^ ^ ^          

TEST_F(LfoTest, triangle_increases_linearly) {
  lfo.set_sample_rate(8);
  lfo.set_rate(8);
  lfo.set_shape(LFO_TRIANGLE);

  lfo.Update();
  lfo.Update();
  lfo.Update();
  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(64, lfo.Render());
}
