#include "acetza/muza/Wave.hpp"

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/sample_rate.hpp"
#include "acetza/muza/types.hpp"

namespace acetza::muza {
Wave::Wave(Channels channels, SampleRate sample_rate)
    : channels_(channels), sample_rate_(sample_rate) {}
Wave::Wave(Frames &&frames, Channels channels, SampleRate sample_rate)
    : frames_(frames), channels_(channels), sample_rate_(sample_rate) {}
Wave Wave::WithDuration(Time duration, Channels channels,
                        SampleRate sample_rate) {
  Index frames_count = sample_rate::TimeToFrame(duration, sample_rate);
  Frames frames = Frames(frames_count.value, Frame(channels));
  return std::move(Wave{std::move(frames), channels, sample_rate});
}
};  // namespace acetza::muza
