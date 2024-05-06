#include "acetza/muza/wavers/Enveloper.hpp"

#include <utility>

#include "acetza/muza/types.hpp"

namespace acetza::muza::wavers {
Enveloper::Enveloper(std::shared_ptr<Waver> waver, Attack attack, Hold hold,
                     Decay decay, Sustain sustain, Release release,
                     EnvelopeTransformers transformers)
    : waver(std::move(waver)),
      attack(attack),
      hold(hold),
      decay(decay),
      sustain(sustain),
      release(release),
      transformers(transformers) {}
}  // namespace acetza::muza::wavers