#pragma once
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Waver.hpp"
namespace acetza::muza::wavers {
struct Enveloper : Waver {
  struct Defaults {
    static constexpr Transformer kTransformer{constants::kTransformer};
    static constexpr Attack kAttack{constants::kAttack};
    static constexpr Hold kHold{constants::kHold};
    static constexpr Decay kDecay{constants::kDecay};
    static constexpr Sustain kSustain{constants::kSustain};
    static constexpr Release kRelease{constants::kRelease};
  };
  explicit Enveloper(Transformer transformer = Defaults::kTransformer,
                     Attack attack = Defaults::kAttack,
                     Hold hold = Defaults::kHold,
                     Decay decay = Defaults::kDecay,
                     Sustain sustain = Defaults::kSustain,
                     Release release = Defaults::kRelease);
  Transformer transformer;
  Attack attack;
  Hold hold;
  Decay decay;
  Sustain sustain;
  Release release;
  class Wave Wave() override;
};
}  // namespace acetza::muza::wavers