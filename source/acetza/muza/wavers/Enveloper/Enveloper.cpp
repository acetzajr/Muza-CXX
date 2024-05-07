#include "acetza/muza/wavers/Enveloper.hpp"

#include <memory>

#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Waver.hpp"

namespace acetza::muza::wavers {
Enveloper::Enveloper(const Enveloper::Args0x0& args)
    : waver(args.waver),
      attack(args.attack),
      hold(args.hold),
      decay(args.decay),
      sustain(args.sustain),
      release(args.release),
      transformers(args.transformers) {}
SharedEnveloper Enveloper::MakeShared(const Enveloper::Args0x0& args) {
  return std::make_shared<Enveloper>(args);
}
}  // namespace acetza::muza::wavers