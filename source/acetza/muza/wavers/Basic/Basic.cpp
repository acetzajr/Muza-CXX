#include "acetza/muza/wavers/Basic.hpp"

#include <memory>

#include "acetza/muza/types.hpp"

namespace acetza::muza {
Basic::Basic(const Args0x0& args)
    : primitive_(args.primitive),
      frequency_(args.frequency),
      duration_(args.duration),
      amplitude_(args.amplitude),
      sample_rate_(args.sample_rate),
      channels_(args.channels) {}
SharedBasic Basic::MakeShared(const Args0x0& args) {
  return std::make_shared<Basic>(args);
}

}  // namespace acetza::muza