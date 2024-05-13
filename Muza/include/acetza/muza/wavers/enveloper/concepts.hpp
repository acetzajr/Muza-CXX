#include "acetza/muza/wavers/concepts.hpp"
namespace acetza::muza::wavers::enveloper {
template <typename T>
concept Waver = Waver<T> && DefaultShared<T>;
} // namespace acetza::muza::wavers::enveloper