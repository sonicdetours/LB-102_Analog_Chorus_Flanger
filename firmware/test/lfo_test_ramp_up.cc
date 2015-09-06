#include "gtest/gtest.h"
#include "lfo_test.h"
#include "../lfo.h"

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
