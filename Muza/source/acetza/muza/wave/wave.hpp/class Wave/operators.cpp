
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza {
wave::Frame &Wave::operator[](Index index) { return frames_[index.value]; }
} // namespace acetza::muza