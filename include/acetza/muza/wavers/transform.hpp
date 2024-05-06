#pragma once
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza::wavers {
struct TransformResult {
  bool disrupted;
  Time end;
  Amplitude last;
};
TransformResult Transform(Wave& wave, Transformer transformer, Time start_time,
                          Amplitude start_amplitude, Time end_time,
                          Amplitude end_amplitude, Duration duration);
}  // namespace acetza::muza::wavers