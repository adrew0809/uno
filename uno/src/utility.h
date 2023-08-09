#ifndef UNO_UTILITY_H_
#define UNO_UTILITY_H_

#include "type_traits.h"

namespace uno {

template<class T>
constexpr T&& forward(remove_reference_t<T>& t) noexcept {
  return static_cast<T&&>(t);
}

template<class T>
constexpr T&& forward(remove_reference_t<T>&& t) noexcept {
  static_assert(!is_lvalue_reference_v<T>,
	  "forward must not be used to convert an rvalue to an lvalue");
  return static_cast<T&&>(t);
}

}  // namespace uno

#endif  // UNO_UTILITY_H_
