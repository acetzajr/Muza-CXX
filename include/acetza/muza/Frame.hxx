#pragma once
#include <cstddef>
#include <vector>
namespace acetza::muza {
class Frame {
  std::vector<double> samples_;

 public:
  size_t channels();
  Frame();
  explicit Frame(size_t channels);
  void Print();
};
};  // namespace acetza::muza
