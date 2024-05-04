#pragma once
#include <vector>

#include "acetza/muza/Frame.hpp"
namespace acetza::muza {
class Wave {
  std::vector<Frame> frames_;
  int channels_;
  int sample_rate_;

 public:
  Wave();
  static Wave WithDuration(double duration, int channels, int sample_rate);
};
};  // namespace acetza::muza
