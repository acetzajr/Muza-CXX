
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
namespace mz = acetza::muza;
namespace wv = mz::wavers;
int main(int /*argc*/, char const* /*argv*/[]) {
  wv::Enveloper<wv::Basic> waver{{}};
  waver.Wave().Save();
  return 0;
}
