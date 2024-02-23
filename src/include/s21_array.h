#ifndef CPP2_S21_CONTAINERS_2_SRC_S21_INCLUDE_S21_ARRAY_H
#define CPP2_S21_CONTAINERS_2_SRC_S21_INCLUDE_S21_ARRAY_H

#include <iostream>
#include <limits>

namespace s21 {
template <typename T, size_t N>
class array {
 public:
  // Array Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Array Member functions
  array();
  array(std::initializer_list<value_type> const
            &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array() = default;

  array &operator=(array &&other);
  array &operator=(const array &other);

  // Array Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  // Array Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // Array Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Array Modifiers
  void swap(array &other);
  void fill(const_reference value);

 private:
  T data_[N];
};

}  // namespace s21

#include "../functions/s21_array.tpp"

#endif  // CPP2_S21_CONTAINERS_2_SRC_S21_INCLUDE_S21_ARRAY_H
