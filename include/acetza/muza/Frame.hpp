#pragma once
#include <vector>

#include "acetza/muza/types.hpp"
namespace acetza::muza {
class Frame {
 public:
  struct Defaults {
    static constexpr Channels kChannels{2};
  };
  explicit Frame(Channels channels = Defaults::kChannels);
  Channels channels();
  Sample& operator[](Index);
  Frame& operator+=(Sample);
  Frame& operator=(Sample);
  void Print();

 private:
  std::vector<Sample> samples_;
};
};  // namespace acetza::muza
