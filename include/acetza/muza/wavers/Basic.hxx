#pragma once
#include "acetza/muza/types.hxx"
namespace acetza::muza::wavers {
class Basic {
 public:
  struct Defaults {
    static constexpr SampleRate kSampleRate{44'100};
    static constexpr Channels kChannels{2};
  };
};
}  // namespace acetza::muza::wavers