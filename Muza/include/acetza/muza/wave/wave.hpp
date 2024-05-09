#pragma once

#include <string>

#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/frames.hpp"
namespace acetza::muza {
class Wave {
public:
  struct Defaults {
    static constexpr std::string kWaveSavePath{constants::kWaveSavePath};
    static constexpr Sample kSample{constants::kSample};
    static constexpr Channels kChannels{constants::kChannels};
    static constexpr SampleRate kSampleRate{constants::kSampleRate};
    static constexpr Time kTime{constants::kTime};
    static constexpr Amplitude kAmplitude{constants::kAmplitude};
  };
  struct Args0x0 {
    Channels channels = Defaults::kChannels;
    SampleRate sample_rate = Defaults::kSampleRate;
  };
  explicit Wave(const Args0x0 &);
  explicit Wave(wave::Frames &&frames, const Args0x0 &);
  explicit Wave(Duration duration, const Args0x0 &);
  [[nodiscard]] const class Frames &GetFrames() const;
  [[nodiscard]] Count GetChannelsCount() const;
  [[nodiscard]] Count GetFramesCount() const;
  [[nodiscard]] Duration GetDuration() const;
  [[nodiscard]] wave::Frames &GetFrames();
  void SetDuration(Duration duration, Sample fill = Defaults::kSample);
  wave::Frame &operator[](Index);
  [[nodiscard]] Time FrameToTime(Index frame) const;
  [[nodiscard]] Index TimeToFrame(Time time) const;
  Wave &Save(const std::string &path = Defaults::kWaveSavePath);
  Wave &Add(const Wave &wave, Time time = Defaults::kTime,
            Amplitude amplitude = Defaults::kAmplitude);

private:
  wave::Frames frames_;
  Channels channels_;
  SampleRate sample_rate_;
};
}; // namespace acetza::muza
