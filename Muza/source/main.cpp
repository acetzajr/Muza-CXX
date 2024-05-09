
#include "acetza/muza/wavers/basic.hpp"
#include "acetza/muza/wavers/enveloper.hpp"
namespace mz = acetza::muza;
namespace wv = mz::wavers;
int main() {
  wv::Enveloper<wv::Basic> waver{{wv::Basic{{}}}};
  waver.Wave().Save();
}
