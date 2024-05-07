#include <sndfile.h>

#include <cstddef>
#include <stdexcept>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Wave& Wave::Save(const std::string& path) {
  SF_INFO info;
  info.samplerate = static_cast<int>(sample_rate_.value);
  info.channels = static_cast<int>(channels_.value);
  info.format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
  SNDFILE* file = sf_open(path.c_str(), SFM_WRITE, &info);
  if (file == nullptr) {
    throw std::runtime_error{"file == nullptr"};
  }
  size_t capacity = GetFramesCount().value * channels_.value;
  std::vector<double> samples;
  samples.reserve(capacity);
  for (const Frame& frame : GetFrames()) {
    for (const Sample& sample : frame.Samples()) {
      samples.push_back(sample.value);
    }
  }
  auto requested = static_cast<sf_count_t>(GetFramesCount().value);
  auto written = sf_writef_double(file, samples.data(), requested);
  if (written != requested) {
    throw std::runtime_error{"written != requested"};
  }
  sf_close(file);
  return *this;
}
}  // namespace acetza::muza