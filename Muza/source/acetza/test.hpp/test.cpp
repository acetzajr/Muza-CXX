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
  const auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << std::format("execution time: {} ms\n", duration.count());
}
} // namespace acetza