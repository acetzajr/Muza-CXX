#pragma once
#include <cstddef>
#include <vector>

#include "acetza/muza/Frame.hxx"
namespace acetza::muza {

class Wave {
  std::vector<Frame> frames_;
  int channels_;
  int sample_rate_;

 public:
  struct Defaults {
    static const size_t kSampleRate{44'100};
    static const size_t kChannels{2};
  };
  Wave();
  static Wave WithDuration(double duration, int channels, int sample_rate);
};
};  // namespace acetza::muza
