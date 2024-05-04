#pragma once
#include <vector>
namespace acetza::muza {
class Frame {
  std::vector<double> samples_;

 public:
  int channels();
  Frame();
  Frame(int channels);
  void Print();
};
};  // namespace acetza::muza
