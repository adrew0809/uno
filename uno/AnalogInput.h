#ifndef UNO_UNO_ANALOGINPUT_H_
#define UNO_UNO_ANALOGINPUT_H_

namespace uno {

class AnalogInput {
public:
  AnalogInput(int pin, unsigned int cooldown_ms) noexcept;

  float read() const noexcept;

private:
  int pin_;
  unsigned long cooldown_ms_;
};

}  // namespace uno

#endif  // UNO_UNO_ANALOGINPUT_H_
