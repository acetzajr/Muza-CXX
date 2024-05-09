
#include "acetza/muza/wavers/classes/basic.hpp"
#include "acetza/muza/wavers/classes/enveloper.hpp"
namespace mz = acetza::muza;
int main() {
  mz::Enveloper<mz::Basic> waver{{mz::Basic{{}}}};
  waver.Wave().Save();
}
