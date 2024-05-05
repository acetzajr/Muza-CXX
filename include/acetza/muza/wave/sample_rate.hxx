#pragma once

#include "acetza/muza/types.hxx"
namespace acetza::muza::wave {
Index TimeToFrame(Time time, SampleRate sample_rate);
Time FrameToTime(Index frame, SampleRate sample_rate);
};  // namespace acetza::muza::wave
