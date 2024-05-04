#include <iostream>

#include "acetza/muza/Frame.hxx"
namespace mz = acetza::muza;
int main(int argc, char const *argv[]) {
#ifdef NDEBUG
  // nondebug
  std::cout << "non debug\n";
#else
  // debug code
  std::cout << "debug\n";
#endif
  std::cout << "Hello muza\n";
  mz::Frame frame{4};
  frame.Print();
  return 0;
}
