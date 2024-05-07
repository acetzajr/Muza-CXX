#pragma once
#include <concepts>

#include "acetza/muza/Wave.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza::concepts {
template <typename T>
concept Waver = requires(T obj) {
  { obj.Wave() } -> std::same_as<Wave>;
};
template <typename T>
concept Frequencyr = requires(T obj, Frequency frequency) {
  { obj.GetFrequency() } -> std::same_as<Frequency>;
  obj.SetFrequency(frequency);
};
}  // namespace acetza::muza::concepts
