#pragma once
#include <vector>

#include "acetza/muza/types.hpp"
#include "acetza/muza/wave/frame.hpp"
namespace acetza::muza::wave {
class Frames : public std::vector<Frame> {
public:
  Frames() = default;
  explicit Frames(Count size, Channels channels);
};
}; // namespace acetza::muza::wave
