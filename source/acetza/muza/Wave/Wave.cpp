#include "acetza/muza/Wave.hpp"

#include "acetza/muza/sample_rate.hpp"
#include "acetza/muza/types.hpp"

namespace acetza::muza {
Wave::Wave(const Args0x0& args)
    : channels_(args.channels), sample_rate_(args.sample_rate) {}
Wave::Wave(class Frames&& frames, const Args0x0& args)
    : frames_(frames),
      channels_(args.channels),
      sample_rate_(args.sample_rate) {}
Wave::Wave(Duration duration, const Args0x0& args)
    : channels_(args.channels), sample_rate_(args.sample_rate) {
  Index frames_count = sample_rate::TimeToFrame({duration}, sample_rate_);
  class Frames frames {
    Count{frames_count}, channels_
  };
  frames_ = std::move(frames);
}
};  // namespace acetza::muza
