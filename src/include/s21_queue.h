#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_H_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_H_
#include <iostream>

#include "s21_list.h"

namespace s21 {

template <typename T>
class queue {
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  size_type SizeOfQueue;
  typename s21::list<value_type>::Node* first;
  typename s21::list<value_type>::Node* last;
  void clean();

 public:
  queue();
  queue(std::initializer_list<value_type> const& items);
  queue(const queue& q);
  queue(queue&& q);
  ~queue();

  queue<value_type> operator=(queue&& q);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();

  void push(const_reference value);
  void pop();
  void swap(queue& other);

  // bonus part for queue
  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push(std::forward<Args>(args)), ...);
  }
};
}  // namespace s21

#include "../functions/s21_queue.tpp"

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_H_