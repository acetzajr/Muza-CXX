#include "acetza/muza/sample_rate.hpp"

#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Time Wave::FrameToTime(Index frame) {
  return sample_rate::FrameToTime(frame, sample_rate_);
}
Index Wave::TimeToFrame(Time time) {
  return sample_rate::TimeToFrame(time, sample_rate_);
}
}  // namespace acetza::muza