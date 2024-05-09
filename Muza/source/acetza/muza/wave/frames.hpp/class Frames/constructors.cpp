#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
#include "acetza/muza/wave/frames.hpp"
#include <vector>
namespace acetza::muza::wave {
Frames::Frames(Count size, Channels channels)
    : std::vector<Frame>(size.value, Frame{channels}) {}
} // namespace acetza::muza::wave