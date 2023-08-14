#include <type_traits>

#include <uno/type_traits.h>

namespace {

void test_integral_constant() {
  static_assert(uno::integral_constant<int, 3>::value == 3);
  uno::integral_constant<int, 12> c;
  static_assert(c == 12);
  static_assert(c() == 12);
}

void test_bool_constant() {
  static_assert(uno::bool_constant<true>::value);
  static_assert(!uno::bool_constant<false>());
  static_assert(uno::true_type()());
  static_assert(!uno::false_type::value);
}

void test_is_lvalue_reference() {
  static_assert(uno::is_lvalue_reference_v<int&>);
  static_assert(uno::is_lvalue_reference_v<const int&>);
  static_assert(!uno::is_lvalue_reference_v<int>);
  static_assert(!uno::is_lvalue_reference_v<int&&>);
}

void test_remove_reference() {
  static_assert(
      std::is_same_v<uno::remove_reference_t<int>, int>);
  static_assert(
      std::is_same_v<uno::remove_reference_t<const int&>,
                     const int>);
  static_assert(
      std::is_same_v<uno::remove_reference_t<int&&>, int>);
}

}  // namespace

int main() {
  test_integral_constant();
  test_bool_constant();
  test_is_lvalue_reference();
  test_remove_reference();
}
