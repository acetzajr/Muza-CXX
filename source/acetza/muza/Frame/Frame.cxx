#include "acetza/muza/Frame.hxx"

#include <iostream>

#include "acetza/muza/types.hxx"
namespace acetza::muza {
Frame::Frame(Channels channels) : samples_(channels, 0.0) {}
Channels Frame::channels() { return Channels(samples_.size()); }
void Frame::Print() {
  for (auto &sample : samples_) {
    std::cout << "[" << sample << "]";
  }
  std::cout << "\n";
}
};  // namespace acetza::muza
