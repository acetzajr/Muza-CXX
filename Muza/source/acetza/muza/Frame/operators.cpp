#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Sample& Frame::operator[](Index index) { return samples_[index.value]; }
Frame& Frame::operator=(double value) {
  for (Sample& channel : samples_) {
    channel.value = value;
  }
  return *this;
}
Frame& Frame::operator+=(double value) {
  for (Sample& channel : samples_) {
    channel.value += value;
  }
  return *this;
}
Frame& Frame::operator*=(double value) {
  for (Sample& channel : samples_) {
    channel.value *= value;
  }
  return *this;
}
}  // namespace acetza::muza