#include "acetza/muza/Frames.hpp"

#include <vector>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
Frames::Frames(Count size, Channels channels)
    : std::vector<Frame>(size.value, Frame{channels}) {}
}  // namespace acetza::muza