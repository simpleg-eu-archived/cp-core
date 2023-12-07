#include <gtest/gtest.h>

#include <Result.h>

using namespace cuplan::core;

TEST(ResultTest, Unwrap_ReturnsOkValue) {
  const std::string expected_value = "abcd1234";

  const Result<std::string, std::string> value =
    Result<std::string, std::string>::Ok(std::make_unique<std::string>(expected_value));

  ASSERT_EQ(expected_value, value.Unwrap());
}

TEST(ResultTest, Unwrap_Error_ThrowsException) {
  const std::string error = "error1234";

  const Result<std::string, std::string> value =
    Result<std::string, std::string>::Err(std::make_unique<std::string>(error));

  ASSERT_THROW(value.Unwrap(), std::logic_error);
}

TEST(ResultTest, UnwrapErr_ReturnsErrorValue) {
  const std::string expected_value = "error1234";

  const Result<std::string, std::string> value =
    Result<std::string, std::string>::Err(std::make_unique<std::string>(expected_value));

  ASSERT_EQ(expected_value, value.UnwrapErr());
}

TEST(ResultTest, UnwrapErr_Ok_ThrowsException) {
  const std::string ok = "ok1234";

  const Result<std::string, bool> value =
    Result<std::string, bool>::Ok(std::make_unique<std::string>(ok));

  ASSERT_THROW(value.UnwrapErr(), std::logic_error);
}