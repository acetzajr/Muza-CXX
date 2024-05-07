#pragma once

#include "acetza/muza/Wave.hpp"
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/concepts.hpp"
#include "acetza/muza/wavers/transform.hpp"
namespace acetza::muza {
namespace enveloper {
template <typename T>
concept Waver = concepts::Waver<T> && concepts::Frequencyr<T>;
}  // namespace enveloper
template <enveloper::Waver Waver>
class Enveloper {
 public:
  struct Defaults {
    static constexpr EnvelopeTransformers kTransformers{
        constants::kTransformer, constants::kTransformer,
        constants::kTransformer};
    static constexpr Attack kAttack{constants::kAttack};
    static constexpr Hold kHold{constants::kHold};
    static constexpr Decay kDecay{constants::kDecay};
    static constexpr Sustain kSustain{constants::kSustain};
    static constexpr Release kRelease{constants::kRelease};
  };
  struct Args0x0 {
    Waver waver;
    Attack attack = Defaults::kAttack;
    Hold hold = Defaults::kHold;
    Decay decay = Defaults::kDecay;
    Sustain sustain = Defaults::kSustain;
    Release release = Defaults::kRelease;
    EnvelopeTransformers transformers = Defaults::kTransformers;
  };
  explicit Enveloper(const Args0x0& args);
  [[nodiscard]] class Wave Wave() const;

 private:
  Waver waver_;
  Attack attack_;
  Hold hold_;
  Decay decay_;
  Sustain sustain_;
  Release release_;
  EnvelopeTransformers transformers;
  struct InnerResult {
    Time time;
    Amplitude amplitude;
    Duration total;
  };
  InnerResult Inner(class Wave& wave) const;
};
template <enveloper::Waver Waver>
Enveloper<Waver>::Enveloper(const Enveloper::Args0x0& args)
    : waver_(args.waver),
      attack_(args.attack),
      hold_(args.hold),
      decay_(args.decay),
      sustain_(args.sustain),
      release_(args.release),
      transformers(args.transformers) {}
template <enveloper::Waver Waver>
Enveloper<Waver>::InnerResult Enveloper<Waver>::Inner(class Wave& wave) const {
  Duration total{wave.GetDuration()};
  Duration limit{total.value - release_.value};
  if (limit.value <= 0.0) {
    return {.time{0.0}, .amplitude{1.0}, .total{total}};
  }
  TransformResult result =
      Transform(wave, transformers.attack, Time{0.0}, Amplitude{0.0},
                Time{attack_}, Amplitude{1.0}, limit);
  if (result.disrupted) {
    return {.time{result.time}, .amplitude{result.amplitude}, .total{total}};
  }
  Time hold_end = {attack_.value + hold_.value};
  if (hold_end.value >= limit.value) {
    return {.time{limit}, .amplitude{1.0}, .total{total}};
  }
  Time decay_end = {hold_end.value + decay_.value};
  result = Transform(wave, transformers.decay, Time{hold_end}, Amplitude{1.0},
                     Time{decay_end}, Amplitude{sustain_}, limit);
  if (result.disrupted) {
    return {.time{limit}, .amplitude{result.amplitude}, .total{total}};
  }
  Index sustain_start = wave.TimeToFrame(decay_end);
  Index sustain_end = wave.TimeToFrame({limit});
  for (Index frame_index{sustain_start}; frame_index.value < sustain_end.value;
       frame_index.value++) {
    wave[frame_index] *= sustain_.value;
  }
  return {.time{limit}, .amplitude{sustain_}, .total{total}};
}
template <enveloper::Waver Waver>
Wave Enveloper<Waver>::Wave() const {
  class Wave wave = waver_.Wave();
  Enveloper<Waver>::InnerResult result = Inner(wave);
  Transform(wave, transformers.release, result.time, result.amplitude,
            Time{result.total}, Amplitude{0.0}, result.total);
  return wave;
}
}  // namespace acetza::muza