#include "acetza/test.hpp"
#include "chrono"
#include "iostream"
#include <format>
namespace acetza {
using VoidFn = void (*)();
void Measure(VoidFn fun) {
  const auto start = std::chrono::high_resolution_clock::now();
  fun();
  const auto end = std::chrono::high_resolution_clock::now();
  const auto duration = duration_cast<std::chrono::milliseconds>(end - start);
  double time = static_cast<double>(duration.count()) / 1'000.0;
  std::cout << std::format("> running time: {} s\n", time);
}
} // namespace acetza