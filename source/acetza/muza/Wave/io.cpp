#include <sndfile.h>

#include <stdexcept>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
void Wave::Save(const std::string& path) const {
  SF_INFO info;
  info.samplerate = static_cast<int>(sample_rate_.value);
  info.channels = static_cast<int>(channels_.value);
  info.format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
  SNDFILE* file = sf_open(path.c_str(), SFM_WRITE, &info);
  if (file == nullptr) {
    throw std::runtime_error{"file == nullptr"};
  }
  std::vector<double> samples;
  for (const Frame& frame : Frames()) {
    for (const Sample& sample : frame.Samples()) {
      samples.push_back(sample.value);
    }
  }
  auto requested = static_cast<sf_count_t>(FramesCount().value);
  auto written = sf_writef_double(file, samples.data(), requested);
  if (written != requested) {
    throw std::runtime_error{"written != requested"};
  }
  sf_close(file);
}
}  // namespace acetza::muza