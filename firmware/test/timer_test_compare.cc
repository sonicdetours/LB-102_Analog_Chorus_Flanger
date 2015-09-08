#include "gtest/gtest.h"
#include "timer_test.h"
#include "../timer.h"

TEST_F(TimerTest, compare_min_delay) {
  timer.set_delay(0);
  EXPECT_EQ(45, timer.compare());
}

TEST_F(TimerTest, compare_prescaler_8_max_delay) {
  timer.set_delay(328);
  EXPECT_EQ(223, timer.compare());
}

TEST_F(TimerTest, compare_prescaler_64_min_delay) {
  timer.set_delay(329);
  EXPECT_EQ(1, timer.compare());
}

TEST_F(TimerTest, compare_prescaler_64_max_delay) {
  timer.set_delay(678);
  EXPECT_EQ(191, timer.compare());
}

TEST_F(TimerTest, compare_prescaler_256_min_delay) {
  timer.set_delay(679);
  EXPECT_EQ(1, timer.compare());
}

TEST_F(TimerTest, compare_max_delay) {
  timer.set_delay(1024);
  EXPECT_EQ(189, timer.compare());
}