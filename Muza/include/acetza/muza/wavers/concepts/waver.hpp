#pragma once
#include <concepts>

#include "acetza/muza/wave/wave.hpp"
namespace acetza::muza::wavers {
template <typename T>
concept Waver = requires(T waver) {
  { waver.Wave() } -> std::same_as<Wave>;
};
} // namespace acetza::muza::wavers
