#pragma once
#include <cstddef>
namespace acetza::muza {
template <class T> struct Value {
  T value;
};
struct Double : public Value<double> {};
struct Size : public Value<std::size_t> {};
struct Attack : public Double {};
struct Hold : public Double {};
struct Decay : public Double {};
struct Sustain : public Double {};
struct Release : public Double {};
struct Frequency : public Double {};
struct Amplitude : public Double {};
struct Sample : public Double {};
struct Time : public Double {};
struct Duration : public Double {};
struct Part : public Double {};
struct Index : public Size {};
struct Count : public Size {};
struct Channels : public Size {};
struct SampleRate : public Size {};
using Primitive = Sample (*)(Part part);
using Transformer = Amplitude (*)(Part part);
using Numberer = Index (*)(Index index);
struct EnvelopeTransformers {
  Transformer attack;
  Transformer decay;
  Transformer release;
};
} // namespace acetza::muza