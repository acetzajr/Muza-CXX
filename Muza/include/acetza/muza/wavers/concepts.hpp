#pragma once
#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/wave.hpp"
#include <concepts>
#include <memory>
namespace acetza::muza::wavers {
template <typename T>
concept Waver = requires(T waver) {
  { waver.Wave() } -> std::same_as<Wave>;
};
template <typename T>
concept DefaultShared = requires {
  { T::MakeShared({}) } -> std::same_as<std::shared_ptr<T>>;
};
template <typename T>
concept FrequencyGetter = requires(T obj) {
  { obj.GetFrequency() } -> std::same_as<Frequency>;
};
template <typename T>
concept FrequencySetter =
    requires(T obj, Frequency frequency) { obj.SetFrequency(frequency); };
} // namespace acetza::muza::wavers
