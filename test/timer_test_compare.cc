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
#include "timer_test.h"
#include "nm-102/timer.h"

using namespace nm102;

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