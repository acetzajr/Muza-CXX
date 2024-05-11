#pragma once
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
#include "acetza/muza/wavers/enveloper/concepts.hpp"
#include "acetza/muza/wavers/enveloper/transform.hpp"
namespace acetza::muza::wavers {
template <enveloper::Waver Waver> class Enveloper {
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
  explicit Enveloper(const Args0x0 &args);
  [[nodiscard]] class Wave Wave() const;

private:
  Waver waver_;
  Attack attack_;
  Hold hold_;
  Decay decay_;
  Sustain sustain_;
  Release release_;
  EnvelopeTransformers transformers_;
};
template <enveloper::Waver Waver>
Enveloper<Waver>::Enveloper(const Enveloper::Args0x0 &args)
    : waver_(args.waver), attack_(args.attack), hold_(args.hold),
      decay_(args.decay), sustain_(args.sustain), release_(args.release),
      transformers_(args.transformers) {}

template <enveloper::Waver Waver> Wave Enveloper<Waver>::Wave() const {
  class Wave wave = waver_.Wave();
  enveloper::Until until = enveloper::UntilRelease(
      wave, attack_, hold_, decay_, sustain_, release_, transformers_);
  enveloper::Transform(wave, transformers_.release, until.time, until.amplitude,
                       Time{until.total}, Amplitude{0.0}, until.total);
  return wave;
}
} // namespace acetza::muza::wavers