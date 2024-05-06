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
    static constexpr std::string kWaveSavePath{constants::kWaveSavePath};
    static constexpr Sample kSample{constants::kSample};
    static constexpr Channels kChannels{constants::kChannels};
    static constexpr SampleRate kSampleRate{constants::kSampleRate};
  };
  explicit Wave(Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  explicit Wave(Frames&& frames, Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  explicit Wave(Duration duration, Channels channels = Defaults::kChannels,
                SampleRate sample_rate = Defaults::kSampleRate);
  const class Frames& GetFrames() const;
  Count GetChannelsCount() const;
  Count GetFramesCount() const;
  Duration GetDuration() const;
  class Frames& GetFrames();
  void SetDuration(Duration duration, Sample fill = Defaults::kSample);
  Frame& operator[](Index);
  [[nodiscard]] Time FrameToTime(Index frame) const;
  [[nodiscard]] Index TimeToFrame(Time time) const;
  void Save(const std::string& path = Defaults::kWaveSavePath) const;

 private:
  class Frames frames_;
  Channels channels_;
  SampleRate sample_rate_;
};
};  // namespace acetza::muza
