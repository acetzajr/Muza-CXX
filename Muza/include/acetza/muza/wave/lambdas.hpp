#pragma once
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
namespace acetza::muza::wave {
template <typename T>
concept SampleLambda =
    requires(T lambda, Sample &sample, Frame frame, Channel channel) {
      lambda(sample, frame, channel);
    };

} // namespace acetza::muza::wave
