#include <iostream>
#include <memory>

#include "acetza/muza/primitives.hpp"
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
namespace mz = acetza::muza;
int main(int argc, char const *argv[]) {
  std::cout << "Hello muza\n";
  mz::wavers::Enveloper enveloper{
      std::make_shared<mz::wavers::Basic>(mz::primitives::Saw)};
  enveloper.Wave().Save();
  return 0;
}
