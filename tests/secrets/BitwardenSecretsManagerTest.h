#ifndef BITWARDENSECRETSMANAGERTEST_H
#define BITWARDENSECRETSMANAGERTEST_H
#include <gtest/gtest.h>

#include "secrets/BitwardenSecretsManager.h"

class BitwardenSecretsManagerTest : public testing::Test {
 public:
  explicit BitwardenSecretsManagerTest();

 protected:
  cuplan::core::secrets::BitwardenSecretsManager secrets_manager_;
};

#endif  // BITWARDENSECRETSMANAGERTEST_H
