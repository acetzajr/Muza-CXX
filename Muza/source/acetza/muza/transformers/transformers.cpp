
#include "acetza/muza/transformers.hpp"

#include <cmath>

#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza::transformers {
Amplitude Smooth(Part part) {
  return {std::sin(constants::kHalfPi * part.value)};
}
Amplitude SmoothInverse(Part part) {
  return {std::sin(constants::kHalfPi * part.value + constants::kHalfPi)};
}
}  // namespace acetza::muza::transformers