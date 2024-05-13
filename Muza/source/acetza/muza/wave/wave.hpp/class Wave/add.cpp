#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
#include <algorithm>
namespace acetza::muza {
Wave &Wave::Add(const Wave &other, Time time, Amplitude amplitude) {
  Index start{other.TimeToFrame(time)};
  Index end{start.value + other.GetFramesCount().value};
  if (end.value > GetFramesCount().value) {
    SetFramesCount({end});
  }
  Channels channels{
      std::min(GetChannelsCount().value, other.GetChannelsCount().value)};
  Index other_frame{0};
  for (Index this_frame{start}; this_frame.value < end.value;
       ++this_frame.value) {
    for (Index channel{0}; channel.value < channels.value; ++channel.value) {
      (*this)[this_frame][channel].value +=
          other[other_frame][channel].value * amplitude.value;
    }
    ++other_frame.value;
  }
  return *this;
}
} // namespace acetza::muza