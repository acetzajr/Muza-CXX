#pragma once
#include <cstddef>

namespace acetza::muza {
template <class T>
struct Value {
  T value;
};
struct Frequency : public Value<double> {};
struct Amplitude : public Value<double> {};
struct Sample : public Value<double> {};
struct Time : public Value<double> {};
struct Part : public Value<double> {};
struct Index : public Value<std::size_t> {};
struct Count : public Value<std::size_t> {};
struct Channels : public Value<std::size_t> {};
struct SampleRate : public Value<std::size_t> {};
using Primitive = Sample (*)(Part part);
using Transformer = Amplitude (*)(Part part);
}  // namespace acetza::muza