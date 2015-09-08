#ifndef TIMER_TEST_H_
#define TIMER_TEST_H_

#include "gtest/gtest.h"
#include "../timer.h"


class TimerTest : public ::testing::Test {
 protected:
  Timer timer;
};

#endif