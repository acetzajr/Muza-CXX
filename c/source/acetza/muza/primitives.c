#include "acetza/muza/primitives.h"

#include <math.h>
double AzSaw(double x) { return 1.0 - 2.0 * x; }
double AzSqr(double x) {
  if (x < 0.5) return 1.0;
  return -1.0;
}
double AzTri(double x) {
  if (x < 0.25) return 4.0 * x;
  if (x < 0.75) return 2.0 - 4.0 * x;
  return 4.0 * x - 4.0;
}
double AzSin(double x) { return sin(2.0 * M_PI * x); }
