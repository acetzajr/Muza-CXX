#include "acetza/muza/wavers/basic.hpp"
#include "acetza/muza/wavers/harmonizer.hpp"
#include "acetza/test.hpp"
namespace mz = acetza::muza;
namespace wv = mz::wavers;
void Test0x0() {
  wv::Harmonizer<wv::Basic, wv::Basic> waver{{}};
  waver.Wave().Save();
}
int main() { acetza::Measure(Test0x0); }