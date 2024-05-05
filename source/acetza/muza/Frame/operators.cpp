#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Sample& Frame::operator[](Index index) { return samples_[index.value]; }
Frame& Frame::operator+=(Sample sample) {
  for (Sample& channel : samples_) {
    channel.value += sample.value;
  }
  return *this;
}
Frame& Frame::operator=(Sample sample) {
  for (Sample& channel : samples_) {
    channel.value = sample.value;
  }
  return *this;
}
}  // namespace acetza::muza