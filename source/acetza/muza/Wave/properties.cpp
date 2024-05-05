
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Count Wave::FramesCount() { return {frames_.size()}; }
}  // namespace acetza::muza