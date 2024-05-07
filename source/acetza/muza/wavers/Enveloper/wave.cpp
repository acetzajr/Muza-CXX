#include "acetza/muza/Wave.hpp"

#include "acetza/muza/types.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
#include "acetza/muza/wavers/concepts.hpp"
#include "acetza/muza/wavers/transform.hpp"
namespace acetza::muza {
template <concepts::Waver Waver>
Enveloper<Waver>::InnerResult Enveloper<Waver>::Inner(class Wave &wave) {
  Duration total{wave.GetDuration()};
  Duration limit{total.value - release_.value};
  if (limit.value <= 0.0) {
    return {.time{0.0}, .amplitude{1.0}, .total{total}};
  }
  TransformResult result =
      Transform(wave, transformers.attack, Time{0.0}, Amplitude{0.0},
                Time{attack_}, Amplitude{1.0}, limit);
  if (result.disrupted) {
    return {.time{result.time}, .amplitude{result.amplitude}, .total{total}};
  }
  Time hold_end = {attack_.value + hold_.value};
  if (hold_end.value >= limit.value) {
    return {.time{limit}, .amplitude{1.0}, .total{total}};
  }
  Time decay_end = {hold_end.value + decay_.value};
  result = Transform(wave, transformers.decay, Time{hold_end}, Amplitude{1.0},
                     Time{decay_end}, Amplitude{sustain_}, limit);
  if (result.disrupted) {
    return {.time{limit}, .amplitude{result.amplitude}, .total{total}};
  }
  Index sustain_start = wave.TimeToFrame(decay_end);
  Index sustain_end = wave.TimeToFrame({limit});
  for (Index frame_index{sustain_start}; frame_index.value < sustain_end.value;
       frame_index.value++) {
    wave[frame_index] *= sustain_.value;
  }
  return {.time{limit}, .amplitude{sustain_}, .total{total}};
}
Wave Enveloper::Wave() {
  auto wave = waver_->Wave();
  auto result = Inner(wave);
  Transform(wave, transformers.release, result.time, result.amplitude,
            Time{result.total}, Amplitude{0.0}, result.total);
  return wave;
}
}  // namespace acetza::muza