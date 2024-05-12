#pragma once
#include "acetza/muza/functions/primitives.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza::wavers {
class Basic {
public:
  struct Defaults {
    static constexpr Primitive kPrimitive{primitives::Sin};
    static constexpr Frequency kFrequency{360.0};
    static constexpr Duration kDuration{1.0};
    static constexpr Amplitude kAmplitude{1.0};
    static constexpr SampleRate kSampleRate{44'100};
    static constexpr Channels kChannels{2};
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