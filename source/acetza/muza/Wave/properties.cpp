
#include "acetza/muza/Frames.hpp"
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Count Wave::FramesCount() const { return {frames_.size()}; }
const class Frames& Wave::Frames() const { return frames_; }
class Frames& Wave::Frames() { return frames_; }
}  // namespace acetza::muza