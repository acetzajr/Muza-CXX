#include "acetza/muza/Frames.hpp"

#include "acetza/muza/Frame.hpp"
namespace acetza::muza {
Frames::Frames(Count size, Channels channels)
    : std::vector<Frame>(size.value, Frame{channels}) {}
}  // namespace acetza::muza