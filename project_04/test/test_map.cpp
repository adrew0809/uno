#include <cassert>
#include <cmath>

#include <uno/array.h>

#include "map.h"

namespace uno {
namespace {

void test_map() {
  array<int, 3> in = { 64, 128, 512 };
  const auto out = map(in);
  assert(out[0] == 16);
  assert(out[1] == 32);
  assert(out[2] == 128);
}

}  // namespace
}  // namespace uno

int main() {
  uno::test_map();
}
