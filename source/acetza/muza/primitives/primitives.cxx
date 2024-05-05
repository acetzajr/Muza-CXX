#include "acetza/muza/primitives.hxx"

#include <cmath>
#include <numbers>
namespace acetza::muza::primitives {
double Saw(double part) { return 1.0 - 2.0 * part; }
double Sqr(double part) { return part < 0.5 ? 1.0 : -1.0; }
double Tri(double part) {
  if (part < 0.25) {
    return 4.0 * part;
  }
  if (part < 0.75) {
    return 2.0 - 4.0 * part;
  }
  return 4.0 * part - 4.0;
}
double Sin(double part) { return std::sin(2.0 * std::numbers::phi * part); }
}  // namespace acetza::muza::primitives