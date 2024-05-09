
#include "acetza/muza/functions/transformers.hpp"
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include <cmath>
namespace acetza::muza::transformers {
Amplitude Smooth(Part part) {
  return {std::sin(constants::kHalfPi.value * part.value)};
}
Amplitude SmoothInverse(Part part) {
  return {std::sin(constants::kHalfPi.value * part.value +
                   constants::kHalfPi.value)};
}
} // namespace acetza::muza::transformers