#pragma once
#include "acetza/muza/functions/numberers.hpp"
#include "acetza/muza/functions/primitives.hpp"
#include "acetza/muza/functions/transformers.hpp"
#include "acetza/muza/types.hpp"
#include <numbers>
#include <string>
namespace acetza::muza::constants {
constexpr Time kTime{0};
constexpr std::string kWaveSavePath{"tmp/wave.wav"};
constexpr Sample kSample{0.0};
constexpr Double kHalfPi{std::numbers::pi / 2.0};
constexpr Transformer kTransformer{transformers::Smooth};
constexpr Attack kAttack{1.0 / 16.0};
constexpr Hold kHold{1.0 / 12.0};
constexpr Decay kDecay{1.0 / 8.0};
constexpr Sustain kSustain{1.0 / 2.0};
constexpr Release kRelease{1.0 / 4.0};
constexpr Primitive kPrimitive{primitives::Sin};
constexpr Frequency kFrequency{360.0};
constexpr Duration kDuration{1.0};
constexpr Amplitude kAmplitude{1.0};
constexpr SampleRate kSampleRate{44'100};
constexpr Channels kChannels{2};
constexpr Count kHarmnonicsCount{7};
constexpr Numberer kNumberer{numberers::Saw};
} // namespace acetza::muza::constants