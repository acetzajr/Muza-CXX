#include "acetza/muza/Frame.hpp"

#include "acetza/muza/types.hpp"
namespace acetza::muza {
Frame::Frame(Channels channels, Sample sample) : samples_({channels}, sample) {}
};  // namespace acetza::muza
