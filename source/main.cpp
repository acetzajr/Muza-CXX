#include <iostream>

#include "acetza/muza/Frame.hpp"
namespace mz = acetza::muza;
int main(int argc, char const *argv[]) {
  std::cout << "Hello muza\n";
  mz::Frame frame;
  frame.Print();
  return 0;
}
