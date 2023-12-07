#ifndef ISECRETSMANAGER_H
#define ISECRETSMANAGER_H
#include "Error.h"
#include "Result.h"

namespace cuplan::core::secrets {
class ISecretsManager {
 public:
  virtual ~ISecretsManager() = default;
  [[nodiscard]] virtual Result<std::string, Error> Get(
      const std::string& secret_id) const = 0;
};
}  // namespace cuplan::core::secrets

#endif  // ISECRETSMANAGER_H
