#include "acetza/muza/functions/numberers.hpp"
#include "acetza/muza/types.hpp"
#include <vector>
namespace acetza::muza::numberers {
Index Saw(Index index) { return index; }
Index Sqr(Index index) { return {2 * index.value - 1}; }
Index Fib(Index index) {
  static std::vector<Index> fibs{{0}, {1}, {1}};
  index.value++;
  while (fibs.size() <= index.value) {
  }
  for (Size size{fibs.size()}; size.value <= index.value;
       index.value++, size = {fibs.size()}) {
    Index next_fib{fibs[size.value - 1].value + fibs[size.value - 2].value};
    fibs.push_back(next_fib);
  }
  return fibs[index.value];
}
} // namespace acetza::muza::numberers