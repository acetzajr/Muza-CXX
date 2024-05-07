#include "acetza/muza/Wave.hpp"

#include <cmath>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Basic.hpp"
namespace acetza::muza {
Wave Basic::Wave() const {
  class Wave wave {
    duration_, { channels_, sample_rate_ }
  };
  Index index{0};
  for (Frame &frame : wave.GetFrames()) {
    Time time = wave.FrameToTime(index);
    Part part = {std::fmod(time.value * frequency_.value, 1.0)};
    Sample sample = {primitive_(part).value * amplitude_.value};
    frame = sample.value;
    index.value++;
  }
  return wave;
}
}  // namespace acetza::muza