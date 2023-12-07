#include <gtest/gtest.h>

#include "Error.h"

TEST(ErrorTest, ErrorKind_ReturnsExpectedString) {
  const std::string expected_error_kind = "errorKind";

  const Error error = Error(expected_error_kind, "");

  ASSERT_EQ(expected_error_kind, error.ErrorKind());
}

TEST(ErrorTest, Message_ReturnsExpectedString) {
  const std::string expected_message = "message";

  const Error error = Error("", expected_message);

  ASSERT_EQ(expected_message, error.Message());
}