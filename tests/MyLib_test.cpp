#include <gtest/gtest.h>

#include <myLib/MyLib.hpp>

TEST(MyLib, sayhello) {

  MyLib theLib;

  EXPECT_TRUE(theLib.sayHello());

  EXPECT_TRUE(theLib.sayGoodbye());
}
