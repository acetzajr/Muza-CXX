#pragma once

#include "acetza/muza/types.hpp"
namespace acetza::muza::sample_rate {
Index TimeToFrame(Time time, SampleRate sample_rate);
Time FrameToTime(Index frame, SampleRate sample_rate);
}; // namespace acetza::muza::sample_rate
