
#include <type_traits>

#include "utility.h"

namespace {

template<class T>
void lvalue_checker(T&& t) {
  static_assert(
      std::is_same_v<decltype(uno::forward<T>(t)),
                     T&>);
}

template<class T>
void rvalue_checker(T&& t) {
  static_assert(
      std::is_same_v<decltype(uno::forward<T>(t)),
                     T&&>);
}

void test_forward() {
  int x = 10;
  lvalue_checker(x);
  int& y = x;
  lvalue_checker(y);
  rvalue_checker(int(11));
}

}  // namespace

int main() {
  void test_forward();
}
