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
  struct Args0x0 {
    Channels channels = Defaults::kChannels;
    SampleRate sample_rate = Defaults::kSampleRate;
  };
  explicit Wave(const Args0x0&);
  explicit Wave(Frames&& frames, const Args0x0&);
  explicit Wave(Duration duration, const Args0x0&);
  [[nodiscard]] const class Frames& GetFrames() const;
  [[nodiscard]] Count GetChannelsCount() const;
  [[nodiscard]] Count GetFramesCount() const;
  [[nodiscard]] Duration GetDuration() const;
  class Frames& GetFrames();
  void SetDuration(Duration duration, Sample fill = Defaults::kSample);
  Frame& operator[](Index);
  [[nodiscard]] Time FrameToTime(Index frame) const;
  [[nodiscard]] Index TimeToFrame(Time time) const;
  Wave& Save(const std::string& path = Defaults::kWaveSavePath);

 private:
  class Frames frames_;
  Channels channels_;
  SampleRate sample_rate_;
};
};  // namespace acetza::muza
