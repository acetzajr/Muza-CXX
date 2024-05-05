#pragma once

#include "acetza/muza/Frame.hxx"
#include "acetza/muza/types.hxx"
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
  Wave();
  Wave(Frames &&frames, Channels channels, SampleRate sample_rate);
  static Wave WithDuration(Time duration,
                           Channels channels = Defaults::kChannels,
                           SampleRate sample_rate = Defaults::kSampleRate);
  [[nodiscard]] Time FrameToTime(Index frame) const;
  [[nodiscard]] Index TimeToFrame(Time time) const;
};
};  // namespace acetza::muza
