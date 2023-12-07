#include "BitwardenSecretsManagerTest.h"

#include <gtest/gtest.h>

#include "Error.h"
#include "Result.h"
#include "secrets/BitwardenSecretsManager.h"
#include "secrets/ErrorKind.h"

using namespace cuplan::core;
using namespace cuplan::core::secrets;

BitwardenSecretsManagerTest::BitwardenSecretsManagerTest()
    : secrets_manager_(std::getenv("SECRETS_MANAGER_ACCESS_TOKEN")) {}

TEST_F(BitwardenSecretsManagerTest, Get_CorrectSecret_ReturnsExpectedSecret) {
  const std::string expected_value = "le_secret :)";
  const std::string secret = "7c1d5dfd-a58b-47cf-bee5-b0a600fe50c9";

  const Result<std::string, Error> result = secrets_manager_.Get(secret);

  ASSERT_TRUE(result.IsOk());
  ASSERT_EQ(expected_value, result.Unwrap());
}

TEST_F(BitwardenSecretsManagerTest, Get_InexistingSecret_ReturnsError) {
  const std::string inexisting_secret = "00000000-0000-0000-0000-000000000000";

  const Result<std::string, Error> result =
      secrets_manager_.Get(inexisting_secret);

  ASSERT_FALSE(result.IsOk());
  ASSERT_EQ(kCommandFailed, result.UnwrapErr().ErrorKind());
}

TEST_F(BitwardenSecretsManagerTest, Get_InvalidSecret_ReturnsError) {
  const std::string invalid_secret = "abcd1234";

  const Result<std::string, Error> result =
      secrets_manager_.Get(invalid_secret);

  ASSERT_FALSE(result.IsOk());
  ASSERT_EQ(kCommandFailed, result.UnwrapErr().ErrorKind());
}