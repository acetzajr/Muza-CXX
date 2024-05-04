#include "acetza/muza/Frame.hpp"

#include <iostream>
namespace acetza::muza {
Frame::Frame() : samples_{0.0, 0.0} {}
Frame::Frame(int channels) : samples_(channels, 0.0) {}
int Frame::channels() { return samples_.size(); }
void Frame::Print() {
  for (auto &sample : samples_) {
    std::cout << "[" << sample << "]";
  }
  std::cout << "\n";
}
};  // namespace acetza::muza
