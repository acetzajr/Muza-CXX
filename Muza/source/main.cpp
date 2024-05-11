#include "acetza/muza/wavers/basic.hpp"
#include "acetza/muza/wavers/enveloper.hpp"
#include "acetza/test.hpp"
namespace mz = acetza::muza;
namespace wv = mz::wavers;
void Test0x0() {
  wv::Enveloper<wv::Basic> waver{{wv::Basic{{}}}};
  waver.Wave().Save();
}
int main() { acetza::Measure(Test0x0); }