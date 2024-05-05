#include "acetza/muza//wave/sample_rate.hxx"

#include "acetza/muza/Wave.hxx"
#include "acetza/muza/types.hxx"
namespace acetza::muza {
Time Wave::FrameToTime(Index frame) const {
  return wave::FrameToTime(frame, sample_rate_);
}
Index Wave::TimeToFrame(Time time) const {
  return wave::TimeToFrame(time, sample_rate_);
}
}  // namespace acetza::muza