#include "acetza/muza/sample_rate.hpp"

#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Time Wave::FrameToTime(Index frame) const {
  return sample_rate::FrameToTime(frame, sample_rate_);
}
Index Wave::TimeToFrame(Time time) const {
  return sample_rate::TimeToFrame(time, sample_rate_);
}
}  // namespace acetza::muza