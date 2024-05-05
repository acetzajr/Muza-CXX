#include "acetza/muza/wave/sample_rate.hxx"

namespace acetza::muza::wave {
size_t TimeToFrame(double time, SampleRate sample_rate) {
  return static_cast<size_t>(time * static_cast<double>(sample_rate));
}
double FrameToTime(int frame, SampleRate sample_rate) {
  return static_cast<double>(frame) / static_cast<double>(sample_rate);
}
}  // namespace acetza::muza::wave
