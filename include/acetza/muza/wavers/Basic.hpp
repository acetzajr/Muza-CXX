#pragma once
#include <memory>

#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Waver.hpp"
namespace acetza::muza::wavers {
struct Basic : public Waver {
  struct Defaults {
    static constexpr Primitive kPrimitive{constants::kPrimitive};
    static constexpr Frequency kFrequency{constants::kFrequency};
    static constexpr Duration kDuration{constants::kDuration};
    static constexpr Amplitude kAmplitude{constants::kAmplitude};
    static constexpr SampleRate kSampleRate{constants::kSampleRate};
    static constexpr Channels kChannels{constants::kChannels};
  };
  explicit Basic(Primitive primitive = Defaults::kPrimitive,
                 Frequency frequency = Defaults::kFrequency,
                 Duration duration = Defaults::kDuration,
                 Amplitude amplitude = Defaults::kAmplitude,
                 SampleRate sample_rate = Defaults::kSampleRate,
                 Channels channels = Defaults::kChannels);
  static std::shared_ptr<Basic> MakeShared(
      Primitive primitive = Defaults::kPrimitive,
      Frequency frequency = Defaults::kFrequency,
      Duration duration = Defaults::kDuration,
      Amplitude amplitude = Defaults::kAmplitude,
      SampleRate sample_rate = Defaults::kSampleRate,
      Channels channels = Defaults::kChannels);
  Primitive primitive;
  Frequency frequency;
  Duration duration;
  Amplitude amplitude;
  SampleRate sample_rate;
  Channels channels;
  class Wave Wave() override;
};
}  // namespace acetza::muza::wavers