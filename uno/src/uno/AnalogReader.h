#ifndef UNO_UNO_SRC_UNO_ANALOGREADER_H_
#define UNO_UNO_SRC_UNO_ANALOGREADER_H_

#include <uno/Board.h>

namespace uno {

class AnalogReader {
public:
  explicit constexpr AnalogReader(AnalogPin pin) noexcept
      : pin_(pin) {}
  int read() const noexcept;
private:
  AnalogPin pin_;
};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_ANALOGREADER_H_
