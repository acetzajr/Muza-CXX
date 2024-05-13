#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/samples.hpp"
namespace acetza::muza::wave {
Channels Frame::GetChannelsCount() const { return {samples_.size()}; }
}; // namespace acetza::muza::wave
