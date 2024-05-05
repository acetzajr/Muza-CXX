#pragma once

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
class Wave {
  Frames frames_;
  Channels channels_;
  SampleRate sample_rate_;

 public:
  struct Defaults {
    static constexpr SampleRate kSampleRate{44'100};
    static constexpr Channels kChannels{2};
  };
  explicit Wave(Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  explicit Wave(Frames &&frames, Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  static Wave WithDuration(Time duration,
                           Channels channels = Defaults::kChannels,
                           SampleRate sample_rate = Defaults::kSampleRate);
  Time FrameToTime(Index frame);
  Index TimeToFrame(Time time);
};
};  // namespace acetza::muza
