#include "SerialPort.h"

namespace uno {

SerialPort::SerialPort(const int baud_rate) noexcept {
  Serial.begin(baud_rate);
}

}  // namespace uno
