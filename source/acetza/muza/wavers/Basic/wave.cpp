#include "acetza/muza/Wave.hpp"

#include <cmath>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Basic.hpp"
namespace acetza::muza::wavers {
Wave Basic::Wave() {
  class Wave wave {
    duration, channels, sample_rate
  };
  Index index{0};
  for (Frame &frame : wave.GetFrames()) {
    Time time = wave.FrameToTime(index);
    Part part = {std::fmod(time.value * frequency.value, 1.0)};
    Sample sample = {primitive(part).value * amplitude.value};
    frame = sample.value;
    index.value++;
  }
  return std::move(wave);
}
}  // namespace acetza::muza::wavers