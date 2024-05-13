#include "acetza/muza/wavers/enveloper/transform.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza::wavers::enveloper {

Until UntilRelease(class Wave &wave, Attack attack, Hold hold, Decay decay,
                   Sustain sustain, Release release,
                   EnvelopeTransformers transformers) {
  Duration total{wave.GetDuration()};
  Time limit{total.value - release.value};
  if (limit.value <= 0.0) {
    return {.time{0.0}, .amplitude{1.0}};
  }
  Result result =
      Transform(wave, transformers.attack, Time{0.0}, Amplitude{0.0},
                Time{attack}, Amplitude{1.0}, limit);
  if (result.disrupted) {
    return {.time{result.time}, .amplitude{result.amplitude}};
  }
  Time hold_end = {attack.value + hold.value};
  if (hold_end.value >= limit.value) {
    return {.time{limit}, .amplitude{1.0}};
  }
  Time decay_end = {hold_end.value + decay.value};
  result = Transform(wave, transformers.decay, Time{hold_end}, Amplitude{1.0},
                     Time{decay_end}, Amplitude{sustain}, limit);
  if (result.disrupted) {
    return {.time{limit}, .amplitude{result.amplitude}};
  }
  Index sustain_start = wave.TimeToFrame(decay_end);
  Index sustain_end = wave.TimeToFrame({limit});
  for (Index frame_index{sustain_start}; frame_index.value < sustain_end.value;
       frame_index.value++) {
    wave[frame_index] *= sustain.value;
  }
  return {.time{limit}, .amplitude{sustain}};
}
Result Transform(Wave &wave, Transformer transformer, Time start_time,
                 Amplitude start_amplitude, Time end_time,
                 Amplitude end_amplitude, Time limit) {
  Index frame_limit = wave.TimeToFrame({limit});
  Index start_frame = wave.TimeToFrame(start_time);
  Index end_frame = wave.TimeToFrame(end_time);
  Amplitude amplitude_difference = {end_amplitude.value -
                                    start_amplitude.value};
  Amplitude last_amplitude = {start_amplitude.value +
                              transformer({0.0}).value *
                                  amplitude_difference.value};
  auto frames_count = static_cast<double>(end_frame.value - start_frame.value);
  double index = 1.0;
  for (Index frame_index{start_frame}; frame_index.value < end_frame.value;
       frame_index.value++) {
    if (frame_index.value >= frame_limit.value) {
      return Result{.disrupted = true,
                    .time = wave.FrameToTime(frame_index),
                    .amplitude = last_amplitude};
    }
    Part part = {index / frames_count};
    last_amplitude = {start_amplitude.value +
                      transformer(part).value * amplitude_difference.value};
    wave[frame_index] *= last_amplitude.value;
    index++;
  }
  return Result{
      .disrupted = false, .time = end_time, .amplitude = last_amplitude};
}
} // namespace acetza::muza::wavers::enveloper