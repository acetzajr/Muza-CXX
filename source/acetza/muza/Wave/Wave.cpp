#include "acetza/muza/Wave.hpp"

#include "acetza/muza/sample_rate.hpp"
#include "acetza/muza/types.hpp"

namespace acetza::muza {
Wave::Wave(Channels channels, SampleRate sample_rate)
    : channels_(channels), sample_rate_(sample_rate) {}
Wave::Wave(class Frames &&frames, Channels channels, SampleRate sample_rate)
    : frames_(frames), channels_(channels), sample_rate_(sample_rate) {}
Wave::Wave(Duration duration, Channels channels, SampleRate sample_rate)
    : channels_(channels), sample_rate_(sample_rate) {
  Index frames_count = sample_rate::TimeToFrame({duration}, sample_rate_);
  class Frames frames {
    Count{frames_count}, channels_
  };
  frames_ = std::move(frames);
}
};  // namespace acetza::muza
