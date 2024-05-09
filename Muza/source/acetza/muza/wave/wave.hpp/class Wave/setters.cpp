#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza {
void Wave::SetDuration(Duration duration, Sample fill) {
  Count frames_count = {TimeToFrame({duration})};
  frames_.resize(frames_count.value, wave::Frame{{GetChannelsCount()}, fill});
}
} // namespace acetza::muza