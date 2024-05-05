#pragma once
#include "acetza/muza/Wave.hpp"
namespace acetza::muza {
class Waver {
 public:
  Waver() = default;
  Waver(const Waver &) = default;
  Waver(Waver &&) = default;
  Waver &operator=(const Waver &) = default;
  Waver &operator=(Waver &&) = default;
  virtual ~Waver() = default;
  virtual Wave Wave() = 0;
};
}  // namespace acetza::muza