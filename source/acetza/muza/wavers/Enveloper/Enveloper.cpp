#include "acetza/muza/wavers/Enveloper.hpp"

#include "acetza/muza/types.hpp"

namespace acetza::muza::wavers {
Enveloper::Enveloper(Transformer transformer, Attack attack, Hold hold,
                     Decay decay, Sustain sustain, Release release)
    : transformer(transformer),
      attack(attack),
      hold(hold),
      decay(decay),
      sustain(sustain),
      release(release) {}
}  // namespace acetza::muza::wavers