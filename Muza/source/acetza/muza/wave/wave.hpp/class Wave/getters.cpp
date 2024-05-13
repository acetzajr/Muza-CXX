
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/frames.hpp"
#include "acetza/muza/wave/wave.hpp"
#include <cmath>
namespace acetza::muza {
Count Wave::GetFramesCount() const { return {frames_.size()}; }
Count Wave::GetSamplesCount() const {
  return {GetFramesCount().value * GetChannelsCount().value};
}
Count Wave::GetChannelsCount() const { return {channels_}; }
Duration Wave::GetDuration() const { return {FrameToTime({GetFramesCount()})}; }
Amplitude Wave::GetMaxAmplitude() const {
  Amplitude max{0.0};
  ForEachFrame([&max](wave::Frame frame, Index) {
    frame.ForEachSample([&max](Sample &sample, Index) {
      auto abs = std::abs(sample.value);
      if (abs > max.value) {
        max = {abs};
      }
    });
  });
  return max;
}
} // namespace acetza::muza