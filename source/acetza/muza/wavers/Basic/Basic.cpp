#include "acetza/muza/wavers/Basic.hpp"

#include "acetza/muza/types.hpp"

namespace acetza::muza::wavers {
Basic::Basic(Primitive primitive, Frequency frequency, Time duration,
             Amplitude amplitude, SampleRate sample_rate, Channels channels)
    : primitive_(primitive),
      frequency_(frequency),
      duration_(duration),
      amplitude_(amplitude),
      sample_rate_(sample_rate),
      channels_(channels) {}
}  // namespace acetza::muza::wavers