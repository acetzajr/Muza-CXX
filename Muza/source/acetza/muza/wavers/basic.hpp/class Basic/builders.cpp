#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/basic.hpp"
#include <memory>
namespace acetza::muza::wavers {
Basic::Basic(const Args0x0 &args)
    : primitive_(args.primitive), frequency_(args.frequency),
      duration_(args.duration), amplitude_(args.amplitude),
      sample_rate_(args.sample_rate), channels_(args.channels) {}
Basic::Shared Basic::MakeShared(const Args0x0 &args) {
  return std::make_shared<Basic>(args);
}
} // namespace acetza::muza::wavers