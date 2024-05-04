#pragma once
#include <cstddef>
namespace acetza::muza::wave {
size_t TimeToFrame(double time, size_t sample_rate);
double FrameToTime(size_t frame, size_t sample_rate);
};  // namespace acetza::muza::wave
