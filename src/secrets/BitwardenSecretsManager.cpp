#include "BitwardenSecretsManager.h"

#include <format>
#include <nlohmann/json.hpp>

#include "ErrorKind.h"

namespace cuplan::core::secrets {
BitwardenSecretsManager::BitwardenSecretsManager(std::string access_token) {
  access_token_ = std::move(access_token);
}

Result<std::string, Error> BitwardenSecretsManager::Get(
    const std::string& secret_id) const {
  const std::string command =
      "bws secret get " + secret_id + " --access-token " + access_token_;
  std::array<char, 256> buffer{};
  std::string secret_json;
  FILE* pipe = popen(command.c_str(), "r");

  if (!pipe) {
    return Result<std::string, Error>::Err(std::make_unique<Error>(
        Error(kCommandFailed, "Failed to execute command.")));
  }

  while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
    secret_json += buffer.data();
  }

  if (const int exit_code = pclose(pipe); exit_code != 0) {
    return Result<std::string, Error>::Err(std::make_unique<Error>(
        Error(kCommandFailed,
              "Failed to retrieve secret, secrets manager exited with code: " +
                  exit_code)));
  }

  try {
    nlohmann::json json_result = nlohmann::json::parse(secret_json);

    return Result<std::string, Error>::Ok(
        std::make_unique<std::string>(json_result["value"]));
  } catch (nlohmann::detail::exception& e) {
    const std::string exception_message = e.what();
    return Result<std::string, Error>::Err(std::make_unique<Error>(
        kInvalidJson,
        "Secret's result is an invalid json: " + exception_message));
  }
}

}  // namespace cuplan::core::secrets