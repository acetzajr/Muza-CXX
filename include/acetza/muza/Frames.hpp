#pragma once
#include <vector>

#include "acetza/muza/Frame.hpp"
#include "acetza/muza/types.hpp"
namespace acetza::muza {
class Frames : public std::vector<Frame> {
 public:
  Frames() = default;
  explicit Frames(Count size, Channels channels);
};
};  // namespace acetza::muza
