#include "acetza/muza/Wave.hpp"

#include <algorithm>

#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
#include "acetza/muza/wavers/transform.hpp"
namespace acetza::muza::wavers {
/*
Wave Enveloper::Wave() {
  class Wave wave = waver->Wave();
  Duration initial_duration = wave.GetDuration();
  Duration total_duration = {release.value + initial_duration.value};
  TransformResult result =
      Transform(wave, transformers.attack, Time{0.0}, Amplitude{0.0},
                Time{attack}, Amplitude{1.0}, initial_duration);
  if (result.disrupted) {
    Transform(wave, transformers.release, Time{result.end},
              Amplitude{result.last}, Time{total_duration}, Amplitude{0.0},
              total_duration);
    return wave;
  }
  Time hold_end = {attack.value + hold.value};
  if (hold_end.value >= initial_duration.value) {
    Transform(wave, transformers.release, Time{initial_duration},
              Amplitude{1.0}, Time{total_duration}, Amplitude{0.0},
              total_duration);
    return wave;
  }
  Time decay_end = {hold_end.value + decay.value};
  result = Transform(wave, transformers.decay, Time{hold_end}, Amplitude{1.0},
                     Time{decay_end}, Amplitude{sustain}, initial_duration);
  if (result.disrupted) {
    Transform(wave, transformers.release, Time{result.end},
              Amplitude{result.last}, Time{total_duration}, Amplitude{0.0},
              total_duration);
    return wave;
  }
  Index sustain_start = wave.TimeToFrame(decay_end);
  Index sustain_end = wave.TimeToFrame({initial_duration});
  for (Index frame_index{sustain_start}; frame_index.value < sustain_end.value;
       frame_index.value++) {
    wave[frame_index] *= sustain.value;
  }
  Transform(wave, transformers.release, Time{initial_duration},
            Amplitude{sustain}, Time{total_duration}, Amplitude{0.0},
            total_duration);
  return wave;
}*/
Enveloper::InnerResult Enveloper::Inner(class Wave &wave) {
  Duration total{wave.GetDuration()};
  Duration limit{total.value - release.value};
  if (limit.value < 0.0) {
    return {.time{0.0}, .amplitude{0.0}, .total{total}};
  }
  TransformResult result =
      Transform(wave, transformers.attack, Time{0.0}, Amplitude{0.0},
                Time{attack}, Amplitude{1.0}, limit);
  if (result.disrupted) {
    return {.time{result.time}, .amplitude{result.amplitude}, .total{total}};
  }
  Time hold_end = {attack.value + hold.value};
  if (hold_end.value >= limit.value) {
    return {.time{limit}, .amplitude{1.0}, .total{total}};
  }
  Time decay_end = {hold_end.value + decay.value};
  result = Transform(wave, transformers.decay, Time{hold_end}, Amplitude{1.0},
                     Time{decay_end}, Amplitude{sustain}, limit);
  if (result.disrupted) {
    return {.time{limit}, .amplitude{result.amplitude}, .total{total}};
  }
  Index sustain_start = wave.TimeToFrame(decay_end);
  Index sustain_end = wave.TimeToFrame({limit});
  for (Index frame_index{sustain_start}; frame_index.value < sustain_end.value;
       frame_index.value++) {
    wave[frame_index] *= sustain.value;
  }
  return {.time{limit}, .amplitude{sustain}, .total{total}};
}
Wave Enveloper::Wave() {
  class Wave wave {
    std::move(waver->Wave())
  };
  auto result = Inner(wave);
  Transform(wave, transformers.release, result.time, result.amplitude,
            Time{result.total}, Amplitude{0.0}, result.total);
  return std::move(wave);
}
}  // namespace acetza::muza::wavers