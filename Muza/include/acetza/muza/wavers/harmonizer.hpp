#pragma once
#include "acetza/muza/functions/numberers.hpp"
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
#include "acetza/muza/wavers/harmonizer/concepts.hpp"
#include <memory>
namespace acetza::muza::wavers {
template <harmonizer::Fundamental Fundamental, harmonizer::Harmonic Harmonic>
class Harmonizer {
public:
  struct Defaults {
    static constexpr Count kHarmnonicsCount{7};
    static constexpr Numberer kNumberer{numberers::Saw};
  };
  struct Args0x0 {
    std::shared_ptr<Fundamental> fundamental = Fundamental::MakeShared({});
    std::shared_ptr<Harmonic> harmonic = Harmonic::MakeShared({});
    Count harmnonics_count = Defaults::kHarmnonicsCount;
    Numberer numberer = Defaults::kNumberer;
  };
  explicit Harmonizer(const Args0x0 &args);
  [[nodiscard]] class Wave Wave() const;

private:
  std::shared_ptr<Fundamental> fundamental_;
  std::shared_ptr<Harmonic> harmonic_;
  Count harmnonics_count_;
  Numberer numberer_;
};
template <harmonizer::Fundamental Fundamental, harmonizer::Harmonic Harmonic>
Harmonizer<Fundamental, Harmonic>::Harmonizer(const Args0x0 &args)
    : fundamental_(args.fundamental), harmonic_(args.harmonic),
      harmnonics_count_(args.harmnonics_count), numberer_(args.numberer) {}
template <harmonizer::Fundamental Fundamental, harmonizer::Harmonic Harmonic>
class Wave Harmonizer<Fundamental, Harmonic>::Wave() const {
  class Wave wave = fundamental_->Wave();
  for (Index index{2}; index.value - 1 <= harmnonics_count_.value;
       index.value++) {
    Index number{numberer_(index)};
    Frequency frequency = {fundamental_->GetFrequency().value * number.value};
    harmonic_->SetFrequency(frequency);
    wave.Add(harmonic_->Wave(), Time{0.0},
             Amplitude{1.0 / static_cast<double>(number.value)});
  }
  wave.Normalize();
  return wave;
}
} // namespace acetza::muza::wavers
