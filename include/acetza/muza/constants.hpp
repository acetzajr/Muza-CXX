#pragma once
#include <numbers>

#include "acetza/muza/primitives.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza::constants {
constexpr double kHalfPi{std::numbers::pi / 2.0};
constexpr Primitive kPrimitive{primitives::Sin};
constexpr Frequency kFrequency{360.0};
constexpr Time kDuration{1.0};
constexpr Amplitude kAmplitude{1.0};
constexpr SampleRate kSampleRate{44'100};
constexpr Channels kChannels{2};
}  // namespace acetza::muza::constants