#ifndef UNO_PROJECT_03_PROCESS_H_
#define UNO_PROJECT_03_PROCESS_H_

namespace uno {

enum class Level : char {
  kNone,
  kLow,
  kMedium,
  kHigh
};

struct Output {
  float value;
  float voltage;
  float celsius;
  Level level;
};

Output process(float baseline, float reading) noexcept;

}  // namespace uno

#endif  // UNO_PROJECT_03_PROCESS_H_
