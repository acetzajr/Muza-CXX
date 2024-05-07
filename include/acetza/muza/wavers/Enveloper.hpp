#pragma once
#include <memory>

#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Waver.hpp"
namespace acetza::muza::wavers {
struct Enveloper;
using SharedEnveloper = std::shared_ptr<Enveloper>;
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
  struct Args0x0 {
    SharedWaver waver = Basic::MakeShared({});
    Attack attack = Defaults::kAttack;
    Hold hold = Defaults::kHold;
    Decay decay = Defaults::kDecay;
    Sustain sustain = Defaults::kSustain;
    Release release = Defaults::kRelease;
    EnvelopeTransformers transformers = Defaults::kTransformers;
  };
  explicit Enveloper(const Args0x0& args);
  static SharedEnveloper MakeShared(const Args0x0& args);
  SharedWaver waver;
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
  InnerResult Inner(class Wave& wave);
};
}  // namespace acetza::muza::wavers