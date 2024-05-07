
#include "acetza/muza/wavers/Basic.hpp"
#include "acetza/muza/wavers/Enveloper.hpp"
namespace mz = acetza::muza;
int main(int /*argc*/, char const* /*argv*/[]) {
  mz::Enveloper<mz::Basic> waver{{mz::Basic{{}}}};
  waver.Wave().Save();
  return 0;
}
