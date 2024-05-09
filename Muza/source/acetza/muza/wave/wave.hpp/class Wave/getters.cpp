
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frames.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza {
Count Wave::GetFramesCount() const { return {frames_.size()}; }
Count Wave::GetChannelsCount() const { return {channels_}; }
Duration Wave::GetDuration() const { return {FrameToTime({GetFramesCount()})}; }
wave::Frames &Wave::GetFrames() { return frames_; }
} // namespace acetza::muza