#include "acetza/muza/wavers/Enveloper.hpp"

namespace acetza::muza {
template <enveloper::Waver Waver>
Enveloper<Waver>::Enveloper(const Enveloper::Args0x0& args)
    : waver_(args.waver),
      attack_(args.attack),
      hold_(args.hold),
      decay_(args.decay),
      sustain_(args.sustain),
      release_(args.release),
      transformers(args.transformers) {}
}  // namespace acetza::muza