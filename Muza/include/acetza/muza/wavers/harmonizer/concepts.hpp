#include "acetza/muza/wavers/concepts.hpp"
namespace acetza::muza::wavers::harmonizer {
template <typename T>
concept Fundamental = Waver<T> && FrequencyGetter<T> && DefaultShared<T>;
template <typename T>
concept Harmonic = Waver<T> && FrequencySetter<T> && DefaultShared<T>;
} // namespace acetza::muza::wavers::harmonizer