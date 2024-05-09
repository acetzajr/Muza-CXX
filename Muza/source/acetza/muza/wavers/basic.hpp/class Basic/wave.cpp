#include "acetza/muza/wave/wave.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wavers/basic.hpp"
#include <cmath>
namespace acetza::muza::wavers {
Wave Basic::Wave() const {
  class Wave wave {
    duration_, { channels_, sample_rate_ }
  };
  Index index{0};
  for (wave::Frame &frame : wave.GetFrames()) {
    Time time = wave.FrameToTime(index);
    Part part = {std::fmod(time.value * frequency_.value, 1.0)};
    Sample sample = {primitive_(part).value * amplitude_.value};
    frame = sample.value;
    index.value++;
  }
  return wave;
}
} // namespace acetza::muza::wavers