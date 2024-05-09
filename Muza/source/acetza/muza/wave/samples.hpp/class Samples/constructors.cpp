#include "acetza/muza/wave/samples.hpp"
#include "acetza/muza/types.hpp"
#include <vector>
namespace acetza::muza::wave {
Samples::Samples(Count size, Sample value)
    : std::vector<Sample>(size.value, value) {}
} // namespace acetza::muza::wave