#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza::wave {
Frame::Frame(Channels channels, Sample sample) : samples_({channels}, sample) {}
}; // namespace acetza::muza::wave
