#include <iostream>
#include <memory>

#include "acetza/muza/primitives.hpp"
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
namespace mz = acetza::muza;
int main(int argc, char const *argv[]) {
  std::cout << "Hello muza\n";
  auto basic = mz::wavers::Basic::MakeShared();
  mz::wavers::Enveloper enveloper{basic};
  basic->primitive = mz::primitives::Saw;
  enveloper.Wave().Save();
  return 0;
}
