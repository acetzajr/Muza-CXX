#include <iostream>

#include "acetza/muza/wavers/Basic.hpp"
namespace mz = acetza::muza;
int main(int argc, char const *argv[]) {
  std::cout << "Hello muza\n";
  mz::wavers::Basic basic{};
  basic.Wave().Save("tmp/wave.wav");
  return 0;
}
