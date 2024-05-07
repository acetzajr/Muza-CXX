#include "acetza/muza/Samples.hpp"
#include <vector>

#include "acetza/muza/types.hpp"
namespace acetza::muza {
Samples::Samples(Count size, Sample value)
    : std::vector<Sample>(size.value, value) {}
}  // namespace acetza::muza