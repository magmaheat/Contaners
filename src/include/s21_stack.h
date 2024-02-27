#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_H_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_H_

#include "s21_list.h"

namespace s21 {

template <typename T>
class stack {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  size_type SizeOfStack;
  typename s21::list<value_type>::Node* head;
  void clean();

 public:
  stack();
  stack(std::initializer_list<value_type> const& items);
  stack(const stack& s);
  stack(stack&& s);
  ~stack();

  stack<value_type> operator=(stack&& s);
  stack<value_type> operator=(const stack& s);

  const_reference top();

  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(stack& other);

  // bonus part for stack
  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }
};
}  // namespace s21

#include "../functions/s21_stack.tpp"

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_H_