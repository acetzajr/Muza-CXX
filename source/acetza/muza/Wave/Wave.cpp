#include "acetza/muza/Wave.hpp"
namespace acetza::muza {
Wave::Wave() : frames_{}, channels_{2}, sample_rate_{44'100} {}
Wave Wave::WithDuration(double duration, int channels, int sample_rate) {
  Wave wave{};
  return std::move(wave);
}
};  // namespace acetza::muza
