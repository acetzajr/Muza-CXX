#pragma once
namespace acetza::muza::wave {
int TimeToFrame(double time, int sample_rate);
double FrameToTime(int frame, int sample_rate);
};  // namespace acetza::muza::wave
