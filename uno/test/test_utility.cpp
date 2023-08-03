
#include <cassert>

#include "utility.h"

int main() {
  uno::integer_sequence<int, 0, 1, 2, 3> seq;
  assert(seq.size() == 4);

  const auto idxs = uno::index_sequence_for<int, double, char>();
  assert(idxs.size() == 3);
}
