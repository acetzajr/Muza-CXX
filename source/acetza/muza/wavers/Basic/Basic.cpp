#include "acetza/muza/wavers/Basic.hpp"

#include <memory>

#include "acetza/muza/types.hpp"

namespace acetza::muza::wavers {
Basic::Basic(const Args0x0& args)
    : primitive(args.primitive),
      frequency(args.frequency),
      duration(args.duration),
      amplitude(args.amplitude),
      sample_rate(args.sample_rate),
      channels(args.channels) {}
SharedBasic Basic::MakeShared(const Args0x0& args) {
  return std::make_shared<Basic>(args);
}

}  // namespace acetza::muza::wavers