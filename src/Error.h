#ifndef ERROR_H
#define ERROR_H
#include <string>

class Error {
public:
  Error(const std::string &error_kind, const std::string &message) {
    error_kind_ = error_kind;
    message_ = message;
  }

  [[nodiscard]] std::string ErrorKind() const {
    return error_kind_;
  }

  [[nodiscard]] std::string Message() const {
    return message_;
  }

private:
  std::string error_kind_;
  std::string message_;
};

#endif //ERROR_H
