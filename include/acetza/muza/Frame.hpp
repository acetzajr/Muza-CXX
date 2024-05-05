#pragma once
#include <vector>

#include "acetza/muza/types.hpp"
namespace acetza::muza {
class Frame {
  std::vector<Sample> samples_;

 public:
  struct Defaults {
    static constexpr Channels kChannels{2};
  };
  Channels channels();
  explicit Frame(Channels channels = Defaults::kChannels);
  void Print();
};
using Frames = std::vector<Frame>;
};  // namespace acetza::muza
