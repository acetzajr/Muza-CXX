#include "acetza/muza/Frame.hpp"

#include <iostream>

#include "acetza/muza/types.hpp"
namespace acetza::muza {
Frame::Frame(Channels channels) : samples_(channels.value, {0.0}) {}
Channels Frame::channels() { return {samples_.size()}; }
void Frame::Print() {
  for (auto &sample : samples_) {
    std::cout << "[" << sample.value << "]";
  }
  std::cout << "\n";
}
};  // namespace acetza::muza
