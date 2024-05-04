#include "acetza/muza/Wave.hxx"
namespace acetza::muza {
Wave::Wave()
    : frames_(),
      channels_(Defaults::kChannels),
      sample_rate_(Defaults::kSampleRate) {}
Wave Wave::WithDuration(double duration, int channels, int sample_rate) {
  Wave wave{};
  return std::move(wave);
}
};  // namespace acetza::muza
