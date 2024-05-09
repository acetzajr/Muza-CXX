#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/samples.hpp"
namespace acetza::muza::wave {
Channels Frame::channels() const { return {samples_.size()}; }
const class Samples &Frame::Samples() const { return samples_; }
class Samples &Frame::Samples() { return samples_; }
}; // namespace acetza::muza::wave
