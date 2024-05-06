#include "acetza/muza/Frame.hpp"

#include "acetza/muza/types.hpp"
namespace acetza::muza {
Frame::Frame(Channels channels) : samples_({channels}, {0.0}) {}
};  // namespace acetza::muza
