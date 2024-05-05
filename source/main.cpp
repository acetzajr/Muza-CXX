#include <iostream>

#include "acetza/muza/sample_rate.hpp"
#include "acetza/muza/types.hpp"
namespace mz = acetza::muza;
int main(int argc, char const *argv[]) {
  std::cout << "Hello muza\n";
  std::cout << mz::sample_rate::TimeToFrame(mz::Time{0.5},
                                            mz::SampleRate{44'100})
                   .value;
  std::cout << "\n";
  return 0;
}
