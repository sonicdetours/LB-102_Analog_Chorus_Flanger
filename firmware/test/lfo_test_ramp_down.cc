#include "gtest/gtest.h"
#include "lfo_test.h"
#include "../lfo.h"


// 255 -  *  
//          * 
//            *  
//              *       
//                *  
//                  * 
//                    *  
//   0 -                *
//        ---------------
//        ^ . . . ^ . . .          

TEST_F(LfoTest, ramp_down_starts_high) {
  lfo.set_sample_rate(2);
  lfo.set_rate(8);
  lfo.set_shape(LFO_RAMP_DOWN);
  
  EXPECT_EQ(255, lfo.Render());
}

// 255 -  *  
//          * 
//            *  
//              *       
//                *  
//                  * 
//                    *  
//   0 -                *
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, ramp_down_decreases_linearly) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);
  lfo.set_shape(LFO_RAMP_DOWN);

  lfo.Update();
  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(63, lfo.Render());
}

// 255 -  *  
//          * 
//            *  
//              *       
//                *  
//                  * 
//                    *  
//   0 -                *
//        ---------------
//        ^ . ^ . ^ . ^ .          

TEST_F(LfoTest, ramp_down_goes_high_on_new_cycle) {
  lfo.set_sample_rate(4);
  lfo.set_rate(8);
  lfo.set_shape(LFO_RAMP_DOWN);

  lfo.Update();
  lfo.Update();
  lfo.Update();
  lfo.Update();
  
  EXPECT_EQ(255, lfo.Render());
}