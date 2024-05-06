#include <iostream>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
void Frame::Print() {
  for (auto &sample : samples_) {
    std::cout << "[" << sample.value << "]";
  }
  std::cout << "\n";
}
};  // namespace acetza::muza
