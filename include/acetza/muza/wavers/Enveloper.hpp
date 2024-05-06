#pragma once
#include <memory>

#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Waver.hpp"
namespace acetza::muza::wavers {
struct Enveloper : Waver {
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
  explicit Enveloper(
      std::shared_ptr<Waver> waver = std::make_shared<Basic>(),
      Attack attack = Defaults::kAttack, Hold hold = Defaults::kHold,
      Decay decay = Defaults::kDecay, Sustain sustain = Defaults::kSustain,
      Release release = Defaults::kRelease,
      EnvelopeTransformers transformers = Defaults::kTransformers);
  std::shared_ptr<Waver> waver;
  Attack attack;
  Hold hold;
  Decay decay;
  Sustain sustain;
  Release release;
  EnvelopeTransformers transformers;
  class Wave Wave() override;

 private:
  struct InnerResult {
    Time time;
    Amplitude amplitude;
    Duration total;
  };
  InnerResult Inner(class Wave &wave);
};
}  // namespace acetza::muza::wavers