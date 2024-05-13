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
  [[nodiscard]] Channels GetChannelsCount() const;
  Sample &operator[](Index);
  const Sample &operator[](Index) const;
  Frame &operator=(double);
  Frame &operator+=(double);
  Frame &operator*=(double);
  void Print();
  template <typename Lambda> Frame &ForEachSample(Lambda lambda);
  template <typename Lambda> const Frame &ForEachSample(Lambda lambda) const;

private:
  class Samples samples_;
};
template <typename Lambda> Frame &Frame::ForEachSample(Lambda lambda) {
  for (Index channel{0}; channel.value < GetChannelsCount().value;
       ++channel.value) {
    lambda(samples_.at(channel.value), channel);
  }
  return *this;
}
template <typename Lambda>
const Frame &Frame::ForEachSample(Lambda lambda) const {
  for (Index channel{0}; channel.value < GetChannelsCount().value;
       ++channel.value) {
    lambda(samples_.at(channel.value), channel);
  }
  return *this;
}
}; // namespace acetza::muza::wave
