#ifndef UNO_UNO_SRC_UNO_ANALOGREADER_H_
#define UNO_UNO_SRC_UNO_ANALOGREADER_H_

#include <stdint.h>
#include <uno/Board.h>

namespace uno {

class AnalogReader {
public:
  explicit constexpr AnalogReader(const AnalogPin pin) noexcept
      : pin_(pin.value) {}
  int read() const noexcept;
private:
  uint8_t pin_;
};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_ANALOGREADER_H_
