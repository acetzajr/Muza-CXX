#include "acetza/muza/wave/sample_rate.hpp"
#include "acetza/muza/types.hpp"
#include <cstddef>
namespace acetza::muza::sample_rate {
Index TimeToFrame(Time time, SampleRate sample_rate) {
  return {static_cast<std::size_t>(time.value *
                                   static_cast<double>(sample_rate.value))};
}
Time FrameToTime(Index frame, SampleRate sample_rate) {
  return {static_cast<double>(frame.value) /
          static_cast<double>(sample_rate.value)};
}
} // namespace acetza::muza::sample_rate
