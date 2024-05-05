#include "acetza/muza/Wave.hxx"

#include "acetza/muza/wave/sample_rate.hxx"

namespace acetza::muza {
Wave::Wave()
    : channels_(Defaults::kChannels), sample_rate_(Defaults::kSampleRate) {}
Wave::Wave(Frames &&frames, Channels channels, SampleRate sample_rate)
    : frames_(frames), channels_(channels), sample_rate_(sample_rate) {}
Wave Wave::WithDuration(double duration, Channels channels,
                        SampleRate sample_rate) {
  auto frames_count = wave::TimeToFrame(duration, sample_rate);
  auto frames = Frames(frames_count, Frame(channels));
  return std::move(Wave(std::move(frames), channels, sample_rate));
}
};  // namespace acetza::muza
