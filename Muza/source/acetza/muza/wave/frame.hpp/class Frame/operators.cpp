#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
namespace acetza::muza::wave {
Sample &Frame::operator[](Index index) { return samples_[index.value]; }
Frame &Frame::operator=(double value) {
  for (Sample &channel : samples_) {
    channel.value = value;
  }
  return *this;
}
Frame &Frame::operator+=(double value) {
  for (Sample &channel : samples_) {
    channel.value += value;
  }
  return *this;
}
Frame &Frame::operator*=(double value) {
  for (Sample &channel : samples_) {
    channel.value *= value;
  }
  return *this;
}
} // namespace acetza::muza::wave