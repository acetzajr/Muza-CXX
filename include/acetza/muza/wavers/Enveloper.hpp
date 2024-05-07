#pragma once

#include "acetza/muza/Wave.hpp"
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/concepts.hpp"
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
    Waver waver = Basic{{}};
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
  InnerResult Inner(class Wave& wave);
};
}  // namespace acetza::muza