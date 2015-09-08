#include "gtest/gtest.h"
#include "timer_test.h"
#include "../timer.h"

TEST_F(TimerTest, calculate_prescaler_min_delay) {
  timer.set_delay(0);
  EXPECT_EQ(Prescaler_8, timer.prescaler());
}

TEST_F(TimerTest, calculate_prescaler_8_upper_limit) {
  timer.set_delay(328);
  EXPECT_EQ(Prescaler_8, timer.prescaler());
}

TEST_F(TimerTest, calculate_prescaler_64_lower_limit) {
  timer.set_delay(329);
  EXPECT_EQ(Prescaler_64, timer.prescaler());
}

TEST_F(TimerTest, calculate_prescaler_64_upper_limit) {
  timer.set_delay(678);
  EXPECT_EQ(Prescaler_64, timer.prescaler());
}

TEST_F(TimerTest, calculate_prescaler_256_lower_limit) {
  timer.set_delay(679);
  EXPECT_EQ(Prescaler_256, timer.prescaler());
}

TEST_F(TimerTest, calculate_prescaler_max_delay) {
  timer.set_delay(1023);
  EXPECT_EQ(Prescaler_256, timer.prescaler());
}
