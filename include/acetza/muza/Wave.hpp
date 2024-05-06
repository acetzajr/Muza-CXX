#pragma once

#include <string>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/Frames.hpp"
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
class Wave {
 public:
  struct Defaults {
    static constexpr Channels kChannels{constants::kChannels};
    static constexpr SampleRate kSampleRate{constants::kSampleRate};
  };
  explicit Wave(Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  explicit Wave(Frames&& frames, Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  explicit Wave(Time duration, Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  const class Frames& Frames() const;
  Count ChannelsCount() const;
  Count FramesCount() const;
  class Frames& Frames();
  Frame& operator[](Index);
  [[nodiscard]] Time FrameToTime(Index frame) const;
  [[nodiscard]] Index TimeToFrame(Time time) const;
  void Save(const std::string& path) const;

 private:
  class Frames frames_;
  Channels channels_;
  SampleRate sample_rate_;
};
};  // namespace acetza::muza
