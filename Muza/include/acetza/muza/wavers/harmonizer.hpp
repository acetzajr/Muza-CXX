#pragma once
#include "acetza/muza/constants.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
#include "acetza/muza/wavers/harmonizer/concepts.hpp"
namespace acetza::muza::wavers {
template <harmonizer::Waver Fundamental, harmonizer::Waver Harmonic>
class Harmonizer {
public:
  struct Defaults {
    static constexpr Count kHarmnonicsCount{constants::kHarmnonicsCount};
    static constexpr Numberer kNumberer{constants::kNumberer};
  };
  struct Args0x0 {
    Fundamental fundamental;
    Harmonic harmonic;
    Count harmnonics_count = Defaults::kHarmnonicsCount;
    Numberer numberer = Defaults::kNumberer;
  };
  explicit Harmonizer(const Args0x0 &args);
  [[nodiscard]] class Wave Wave() const;

private:
  Fundamental fundamental_;
  Harmonic harmonic_;
  Count harmnonics_count_;
  Numberer numberer_;
};
template <harmonizer::Waver Fundamental, harmonizer::Waver Harmonic>
Harmonizer<Fundamental, Harmonic>::Harmonizer(const Args0x0 &args)
    : fundamental_(args.fundamental), harmonic_(args.harmonic),
      harmnonics_count_(args.harmnonics_count), numberer_(args.numberer) {}
template <harmonizer::Waver Fundamental, harmonizer::Waver Harmonic>
class Wave Harmonizer<Fundamental, Harmonic>::Wave() const {
  class Wave wave = fundamental_.Wave();
  for (Index index{2}; index.value - 1 <= harmnonics_count_.value;
       index.value++) {
    Index number{numberer_(index)};
    Frequency frequency = {fundamental_.GetFrequency().value * index.value};
    harmonic_.SetFrequency(frequency);
  }
  return wave;
}
} // namespace acetza::muza::wavers
