#ifndef UNO_UNO_SERIALPORT_H_
#define UNO_UNO_SERIALPORT_H_

#include "utility.h"

#include "Arduino.h"

namespace uno {

class SerialPort {
public:
  explicit SerialPort(int baud_rate) noexcept;
  template<class T>
  void print(T&& t) const noexcept {
    Serial.print(uno::forward<T>(t));
  }
};

}  // namespace uno

#endif  // UNO_UNO_SERIALPORT_H_
