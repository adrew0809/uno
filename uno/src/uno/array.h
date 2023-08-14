#ifndef UNO_UNO_SRC_UNO_ARRAY_H_
#define UNO_UNO_SRC_UNO_ARRAY_H_

#include <stddef.h>

namespace uno {

template <class T, size_t N>
struct array {
  using value_type = T;
  using size_type = size_t;
  using difference_type = ptrdiff_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using iterator = pointer;
  using const_iterator = const_pointer;

  T elems_[N];

  constexpr size_type size() const noexcept {
    return N;
  }

	constexpr reference operator[](size_type pos) {
    return elems_[pos];
  }

	constexpr const_reference operator[](size_type pos) const {
    return elems_[pos];
  }

  constexpr iterator begin() noexcept {
    return elems_;
  }

	constexpr const_iterator begin() const noexcept {
    return elems_;
  }

	constexpr const_iterator cbegin() const noexcept {
    return elems_;
  }

  constexpr iterator end() noexcept {
    return &elems_[N];
  }

	constexpr const_iterator end() const noexcept {
    return &elems_[N];
  }

	constexpr const_iterator cend() const noexcept {
    return &elems_[N];
  }

};

}  // namespace uno

#endif  // UNO_UNO_SRC_UNO_ARRAY_H_
