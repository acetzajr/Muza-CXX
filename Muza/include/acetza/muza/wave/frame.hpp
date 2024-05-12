#pragma once
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/samples.hpp"
namespace acetza::muza::wave {
class Frame {
public:
  struct Defaults {
    static constexpr Sample kSample{0.0};
    static constexpr Channels kChannels{2};
  };
  explicit Frame(Channels channels = Defaults::kChannels,
                 Sample sample = Defaults::kSample);
  [[nodiscard]] Channels channels() const;
  [[nodiscard]] const class Samples &Samples() const;
  class Samples &Samples();
  Sample &operator[](Index);
  Frame &operator=(double);
  Frame &operator+=(double);
  Frame &operator*=(double);
  void Print();

private:
  class Samples samples_;
};
}; // namespace acetza::muza::wave
