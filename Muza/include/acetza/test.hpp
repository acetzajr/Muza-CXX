#pragma once
namespace acetza {
using VoidFn = void (*)();
void Measure(VoidFn fun);
} // namespace acetza