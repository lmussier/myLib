#include <gtest/gtest.h>

#include "FirstObject.hpp"

TEST(FirstObject, oneFirstAwesomeMethode) {

  FirstObject theFirstObject;

  EXPECT_TRUE(theFirstObject.oneFirstAwesomeMethode());
}

