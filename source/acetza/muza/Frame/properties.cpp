#include "acetza/muza/Frame.hpp"
#include "acetza/muza/Samples.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Channels Frame::channels() const { return {samples_.size()}; }
const class Samples& Frame::Samples() const { return samples_; }
class Samples& Frame::Samples() { return samples_; }
};  // namespace acetza::muza
