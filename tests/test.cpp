#include <gtest/gtest.h>
#include "testFuncs.hpp"

extern int ret(int a);

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(CrossTest, CrossTest1) {
	EXPECT_EQ(ret(1), 2);
	EXPECT_EQ(ret(2), 4);
}