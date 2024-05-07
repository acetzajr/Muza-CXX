#include <iostream>

#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
namespace mz = acetza::muza;
namespace wr = mz::wavers;
int main(int /*argc*/, char const* /*argv*/[]) {
  std::cout << "Hello muza\n";
  wr::Enveloper waver({.waver = wr::Basic::MakeShared({}), .release{0.5}});
  waver.Wave().Save();
  return 0;
}
