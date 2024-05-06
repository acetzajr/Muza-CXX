#include "acetza/muza/wavers/transform.hpp"

#include "acetza/muza/types.hpp"
namespace acetza::muza::wavers {
TransformResult Transform(Wave& wave, Transformer transformer, Time start_time,
                          Amplitude start_amplitude, Time end_time,
                          Amplitude end_amplitude, Duration duration) {
  Index frame_limit = wave.TimeToFrame({duration});
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
      return TransformResult{.disrupted = true,
                             .end = wave.FrameToTime(frame_index),
                             .last = last_amplitude};
      Part part = {index / frames_count};
      last_amplitude = {start_amplitude.value +
                        transformer(part).value * amplitude_difference.value};
      wave[frame_index] *= last_amplitude.value;
      index++;
    }
  }
  return TransformResult{
      .disrupted = false, .end = end_time, .last = last_amplitude};
}
}  // namespace acetza::muza::wavers