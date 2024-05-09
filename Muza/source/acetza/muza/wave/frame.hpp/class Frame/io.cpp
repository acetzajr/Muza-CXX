#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include <iostream>
namespace acetza::muza::wave {
void Frame::Print() {
  for (Sample &sample : samples_) {
    std::cout << "[" << sample.value << "]";
  }
  std::cout << "\n";
}
}; // namespace acetza::muza::wave
