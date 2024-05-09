#pragma once
#include <concepts>

#include "acetza/muza/types.hpp"
namespace acetza::muza::wavers {
template <typename T>
concept Frequencyr = requires(T frequencyr, Frequency frequency) {
  { frequencyr.GetFrequency() } -> std::same_as<Frequency>;
  frequencyr.SetFrequency(frequency);
};
} // namespace acetza::muza::wavers
