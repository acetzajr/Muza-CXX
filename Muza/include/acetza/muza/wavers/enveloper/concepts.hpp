
#include "acetza/muza/wavers/concepts/frequencyr.hpp"
#include "acetza/muza/wavers/concepts/waver.hpp"
namespace acetza::muza::wavers::enveloper {
template <typename T>
concept Waver = Waver<T> && Frequencyr<T>;
} // namespace acetza::muza::wavers::enveloper