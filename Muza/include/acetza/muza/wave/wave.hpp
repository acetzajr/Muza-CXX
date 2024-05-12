#pragma once
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/frames.hpp"
#include <string>
namespace acetza::muza {
class Wave {
public:
  struct Defaults {
    static constexpr std::string kWaveSavePath{"tmp/wave.wav"};
    static constexpr Sample kSample{0.0};
    static constexpr Channels kChannels{2};
    static constexpr SampleRate kSampleRate{44'100};
    static constexpr Time kTime{0.0};
    static constexpr Amplitude kAmplitude{1.0};
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
