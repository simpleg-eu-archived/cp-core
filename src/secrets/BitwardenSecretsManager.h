

#ifndef BITWARDENSECRETSMANAGER_H
#define BITWARDENSECRETSMANAGER_H
#include <string>

#include "Error.h"
#include "ISecretsManager.h"
#include "Result.h"

namespace cuplan::core::secrets {

class BitwardenSecretsManager final : public ISecretsManager {
 public:
  explicit BitwardenSecretsManager(std::string access_token);
  ~BitwardenSecretsManager() override = default;

  [[nodiscard]] Result<std::string, Error> Get(
      const std::string& secret_id) const override;

 private:
  std::string access_token_;
};

}  // namespace cuplan::core::secrets

#endif  // BITWARDENSECRETSMANAGER_H
