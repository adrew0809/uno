#include "log.h"

#include <uno/Board.h>

namespace uno {

constexpr array<const char*, 3> kColors = {"\t red: ",
                                           "\t green: ",
                                           "\t blue: "};

void log(const SerialStream& ss,
           const char* const intro,
           const array<int, 3>& arr) noexcept {
  ss << intro;
  for (int i = 0; i < 3; ++i) {
    ss << kColors[i];
    ss << arr[i];
  }
  ss << '\n';
}

}  // namespace uno
