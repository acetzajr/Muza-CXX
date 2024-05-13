#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/wave.hpp"
#include <iostream>
namespace acetza::muza {
Wave &Wave::Normalize() {
  Amplitude max{GetMaxAmplitude()};
  std::cout << max.value << "\n";
  ForEachFrame([](wave::Frame frame, Index) {
    frame.ForEachSample(
        [](Sample &sample, Index) { std::cout << sample.value << "\n"; });
  });
  max = GetMaxAmplitude();
  std::cout << max.value << "\n";
  return *this;
}
} // namespace acetza::muza