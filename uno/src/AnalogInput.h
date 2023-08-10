#ifndef UNO_UNO_ANALOGINPUT_H_
#define UNO_UNO_ANALOGINPUT_H_

namespace uno {

class AnalogInput {
public:
  constexpr AnalogInput(const int pin,
                        const unsigned int cooldown_ms) noexcept :
    pin_(pin), cooldown_ms_(cooldown_ms) {}


  int read() const noexcept;

private:
  int pin_;
  unsigned long cooldown_ms_;
};

}  // namespace uno

#endif  // UNO_UNO_ANALOGINPUT_H_
