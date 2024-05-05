#pragma once
#include "acetza/muza/primitives.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Waver.hpp"
namespace acetza::muza::wavers {
class Basic : public Waver {
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