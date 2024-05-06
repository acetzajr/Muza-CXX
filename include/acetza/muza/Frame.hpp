#pragma once

#include "acetza/muza/Samples.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
class Frame {
 public:
  struct Defaults {
    static constexpr Channels kChannels{2};
  };
  explicit Frame(Channels channels = Defaults::kChannels);
  Channels channels() const;
  const class Samples& Samples() const;
  class Samples& Samples();
  Sample& operator[](Index);
  Frame& operator+=(Sample);
  Frame& operator=(Sample);
  void Print();

 private:
  class Samples samples_;
};
};  // namespace acetza::muza
