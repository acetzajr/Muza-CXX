
#include "acetza/muza/Frame.hpp"
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Frame& Wave::operator[](Index index) { return frames_[index.value]; }
}  // namespace acetza::muza