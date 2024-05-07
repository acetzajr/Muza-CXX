#include "acetza/muza/Frame.hpp"
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"

namespace acetza::muza {
void Wave::SetDuration(Duration duration, Sample fill) {
  Count frames_count = {TimeToFrame({duration})};
  frames_.resize(frames_count.value, Frame{{GetChannelsCount()}, fill});
}
}  // namespace acetza::muza