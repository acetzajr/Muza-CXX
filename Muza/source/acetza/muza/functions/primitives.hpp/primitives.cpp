#include "acetza/muza/functions/primitives.hpp"
#include "acetza/muza/types.hpp"
#include <cmath>
#include <numbers>
namespace acetza::muza::primitives {
Sample Saw(Part part) { return {1.0 - 2.0 * part.value}; }
Sample Sqr(Part part) { return {part.value < 0.5 ? 1.0 : -1.0}; }
Sample Tri(Part part) {
  if (part.value < 0.25) {
    return {4.0 * part.value};
  }
  if (part.value < 0.75) {
    return {2.0 - 4.0 * part.value};
  }
  return {4.0 * part.value - 4.0};
}
Sample Sin(Part part) {
  return {std::sin(2.0 * std::numbers::pi * part.value)};
}
} // namespace acetza::muza::primitives