#pragma once
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Waver.hpp"
namespace acetza::muza::wavers {
class Basic : public Waver {
 public:
  struct Defaults {
    static constexpr Primitive kPrimitive{constants::kPrimitive};
    static constexpr Frequency kFrequency{constants::kFrequency};
    static constexpr Time kDuration{constants::kDuration};
    static constexpr Amplitude kAmplitude{constants::kAmplitude};
    static constexpr SampleRate kSampleRate{constants::kSampleRate};
    static constexpr Channels kChannels{constants::kChannels};
  };
  explicit Basic(Primitive primitive = Defaults::kPrimitive,
                 Frequency frequency = Defaults::kFrequency,
                 Time duration = Defaults::kDuration,
                 Amplitude amplitude = Defaults::kAmplitude,
                 SampleRate sample_rate = Defaults::kSampleRate,
                 Channels channels = Defaults::kChannels);
  class Wave Wave() override;

 private:
  Primitive primitive_;
  Frequency frequency_;
  Time duration_;
  Amplitude amplitude_;
  SampleRate sample_rate_;
  Channels channels_;
};
}  // namespace acetza::muza::wavers