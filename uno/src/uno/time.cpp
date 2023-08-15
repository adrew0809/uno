#include <uno/time.h>

#include <Arduino.h>

namespace uno {

void wait_for(Milliseconds ms) noexcept {
  delay(ms.value);
}

}  // namespace uno
