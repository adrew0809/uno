#ifndef UNO_PROJECT_02_WRITER_H_
#define UNO_PROJECT_02_WRITER_H_

#include <uno/array.h>

namespace uno {

class Blinking;
class DigitalWriter;
class Idle;

class Writer {
public:
  Writer(const DigitalWriter& ready,
         const array<DigitalWriter, 2>& blinkers) noexcept;

  void operator()(const Idle& idle) const noexcept;

  void operator()(const Blinking& blinking) const noexcept;

private:
  const DigitalWriter* ready_;
  const array<DigitalWriter, 2>* blinkers_;
};

}  // namespace uno

#endif  // UNO_PROJECT_02_WRITER_H_
