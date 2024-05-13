#pragma once
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza::wavers::enveloper {
struct Until {
  Time time;
  Amplitude amplitude;
};
struct Result {
  bool disrupted;
  Time time;
  Amplitude amplitude;
};
Until UntilRelease(class Wave &wave, Attack attack, Hold hold, Decay decay,
                   Sustain sustain, Release release,
                   EnvelopeTransformers transformers);
Result Transform(Wave &wave, Transformer transformer, Time start_time,
                 Amplitude start_amplitude, Time end_time,
                 Amplitude end_amplitude, Time limit);
} // namespace acetza::muza::wavers::enveloper