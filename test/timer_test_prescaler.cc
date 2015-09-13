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
