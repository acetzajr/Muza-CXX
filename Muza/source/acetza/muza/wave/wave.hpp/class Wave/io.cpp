#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/wave.hpp"
#include <cstddef>
#include <sndfile-64.h>
#include <stdexcept>
#include <string>
#include <vector>
namespace acetza::muza {
Wave &Wave::Save(const std::string &path) {
  SF_INFO info;
  info.samplerate = static_cast<int>(sample_rate_.value);
  info.channels = static_cast<int>(channels_.value);
  info.format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
  SNDFILE *file = sf_open(path.c_str(), SFM_WRITE, &info);
  if (file == nullptr) {
    throw std::runtime_error{"file == nullptr"};
  }
  size_t capacity = GetFramesCount().value * channels_.value;
  std::vector<double> samples;
  samples.reserve(capacity);
  ForEachFrame([&samples](wave::Frame &frame, Index) {
    frame.ForEachSample(
        [&samples](Sample &sample, Index) { samples.push_back(sample.value); });
  });
  sf_count_t requested = static_cast<sf_count_t>(GetFramesCount().value);
  sf_count_t written = sf_writef_double(file, samples.data(), requested);
  if (written != requested) {
    throw std::runtime_error{"written != requested"};
  }
  sf_close(file);
  return *this;
}
} // namespace acetza::muza