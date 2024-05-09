#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frames.hpp"
#include "acetza/muza/wave/sample_rate.hpp"
#include "acetza/muza/wave/wave.hpp"
#include <utility>
namespace acetza::muza {
Wave::Wave(const Args0x0 &args)
    : channels_(args.channels), sample_rate_(args.sample_rate) {}
Wave::Wave(wave::Frames &&frames, const Args0x0 &args)
    : frames_(std::move(frames)), channels_(args.channels),
      sample_rate_(args.sample_rate) {}
Wave::Wave(Duration duration, const Args0x0 &args)
    : channels_(args.channels), sample_rate_(args.sample_rate) {
  Index frames_count = sample_rate::TimeToFrame({duration}, sample_rate_);
  wave::Frames frames{Count{frames_count}, channels_};
  frames_ = std::move(frames);
}
}; // namespace acetza::muza
