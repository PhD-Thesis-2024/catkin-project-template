#include <catch2/catch_test_macros.hpp>

#include "catkin_template/Message.h"


TEST_CASE("Basic test-case: message data should be empty") {
  catkin_template::Message msg;
  REQUIRE(msg.data.empty());
}

TEST_CASE("Basic test-case: message data length > 0") {
  catkin_template::Message msg;
  REQUIRE_FALSE(msg.data.length() > 0);
}