#pragma once
#include <cstddef>

namespace acetza::muza {
struct Index {
  double size_t;
};
struct Sample {
  double value;
};
struct Time {
  double value;
};
struct Channels {
  size_t value;
};
struct SampleRate {
  size_t value;
};
}  // namespace acetza::muza