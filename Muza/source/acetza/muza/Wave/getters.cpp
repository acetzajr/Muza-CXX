
#include "acetza/muza/Frames.hpp"
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Count Wave::GetFramesCount() const { return {frames_.size()}; }
Count Wave::GetChannelsCount() const { return {channels_}; }
const class Frames& Wave::GetFrames() const { return frames_; }
class Frames& Wave::GetFrames() { return frames_; }
Duration Wave::GetDuration() const { return {FrameToTime({GetFramesCount()})}; }
}  // namespace acetza::muza