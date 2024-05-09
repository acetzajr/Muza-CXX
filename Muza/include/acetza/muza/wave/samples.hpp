#pragma once
#include <vector>

#include "acetza/muza/types.hpp"
namespace acetza::muza::wave {
class Samples : public std::vector<Sample> {
public:
  Samples() = default;
  explicit Samples(Count size, Sample value);
};
}; // namespace acetza::muza::wave
