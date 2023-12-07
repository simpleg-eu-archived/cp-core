#ifndef RESULT_H
#define RESULT_H
#include <memory>

namespace cuplan::core {
template <typename TOk, typename TError>
class Result {
 public:
  static Result Ok(std::unique_ptr<TOk> ok) {
    return Result(std::move(ok), nullptr, true);
  }

  static Result Err(std::unique_ptr<TError> error) {
    return Result(nullptr, std::move(error), false);
  }

  TOk Unwrap() const {
    if (!success_) {
      throw std::logic_error(
          "Tried to unwrap 'ok' value when result is an 'error'.");
    }

    return *ok_;
  }

  TError UnwrapErr() const {
    if (success_) {
      throw std::logic_error(
          "Tried to unwrap 'error' value when result is an 'ok'.");
    }

    return *err_;
  }

  bool IsOk() const { return success_; }

 private:
  std::shared_ptr<TOk> ok_;
  std::shared_ptr<TError> err_;

  bool success_;

  Result(std::unique_ptr<TOk> ok, std::unique_ptr<TError> error, bool success) {
    if (ok != nullptr) {
      ok_ = std::move(ok);
    } else {
      ok_ = nullptr;
    }

    if (error != nullptr) {
      err_ = std::move(error);
    } else {
      err_ = nullptr;
    }

    success_ = success;
  }
};
}  // namespace cuplan::core
#endif  // RESULT_H
