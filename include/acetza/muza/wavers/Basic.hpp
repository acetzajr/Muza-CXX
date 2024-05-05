#pragma once
#include "acetza/muza/primitives.hxx"
#include "acetza/muza/types.hxx"
namespace acetza::muza::wavers {
class Basic {
 public:
  struct Defaults {
    static constexpr Primitive kPrimitive{primitives::Sin};
    static constexpr Frequency kFrequency{360.0};
    static constexpr Time kDuration{1.0};
    static constexpr Amplitude kAmplitude{1.0};
    static constexpr SampleRate kSampleRate{44'100};
    static constexpr Channels kChannels{2};
  };
  explicit Basic(Primitive primitive = Defaults::kPrimitive,
                 Frequency frequency = Defaults::kFrequency,
                 Time duration = Defaults::kDuration,
                 Amplitude = Defaults::kAmplitude,
                 SampleRate sample_rate = Defaults::kSampleRate,
                 Channels channels = Defaults::kChannels);
};
}  // namespace acetza::muza::wavers