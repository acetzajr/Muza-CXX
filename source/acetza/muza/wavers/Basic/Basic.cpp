#include "acetza/muza/wavers/Basic.hpp"

#include "acetza/muza/types.hpp"

namespace acetza::muza::wavers {
Basic::Basic(Primitive primitive, Frequency frequency, Duration duration,
             Amplitude amplitude, SampleRate sample_rate, Channels channels)
    : primitive(primitive),
      frequency(frequency),
      duration(duration),
      amplitude(amplitude),
      sample_rate(sample_rate),
      channels(channels) {}
}  // namespace acetza::muza::wavers