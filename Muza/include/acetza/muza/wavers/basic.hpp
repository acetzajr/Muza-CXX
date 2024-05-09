#pragma once

#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza::wavers {
class Basic {
public:
  struct Defaults {
    static constexpr Primitive kPrimitive{constants::kPrimitive};
    static constexpr Frequency kFrequency{constants::kFrequency};
    static constexpr Duration kDuration{constants::kDuration};
    static constexpr Amplitude kAmplitude{constants::kAmplitude};
    static constexpr SampleRate kSampleRate{constants::kSampleRate};
    static constexpr Channels kChannels{constants::kChannels};
  };
  struct Args0x0 {
    Primitive primitive = Defaults::kPrimitive;
    Frequency frequency = Defaults::kFrequency;
    Duration duration = Defaults::kDuration;
    Amplitude amplitude = Defaults::kAmplitude;
    SampleRate sample_rate = Defaults::kSampleRate;
    Channels channels = Defaults::kChannels;
  };
  explicit Basic(const Args0x0 &args);
  [[nodiscard]] Frequency GetFrequency() const;
  void SetFrequency(Frequency frequency);
  [[nodiscard]] class Wave Wave() const;

private:
  Primitive primitive_;
  Frequency frequency_;
  Duration duration_;
  Amplitude amplitude_;
  SampleRate sample_rate_;
  Channels channels_;
};
} // namespace acetza::muza::wavers