#include "acetza/muza/wave/sample_rate.hpp"
int TimeToFrame(double time, int sample_rate) { return time * sample_rate; }
double FrameToTime(int frame, int sample_rate) {
  return (double)frame / sample_rate;
}
