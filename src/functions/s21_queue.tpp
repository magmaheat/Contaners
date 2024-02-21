#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_TPP_

namespace s21 {

template <typename T>
queue<T>::queue() {
  SizeOfQueue = 0;
  first = nullptr;
  last = nullptr;
}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const& items)
    : SizeOfQueue(0), first(nullptr), last(nullptr) {
  for (const auto& item : items) {
    push(item);
  }
}

template <typename T>
queue<T>::queue(const queue& q)
    : SizeOfQueue(0), first(nullptr), last(nullptr) {
  typename s21::list<value_type>::Node* current = q.first;
  while (current != nullptr) {
    push(current->value);
    current = current->next;
  }
}

template <typename T>
queue<T>::queue(queue&& q)
    : SizeOfQueue(q.SizeOfQueue), first(q.first), last(q.last) {
  q.SizeOfQueue = 0;
  q.first = nullptr;
  q.last = nullptr;
}

template <typename T>
queue<T>::~queue() {
  clean();
}

template <typename T>
queue<T> queue<T>::operator=(queue<T>&& other) {
  if (this != std::addressof(other)) {
    clean();
    SizeOfQueue = other.SizeOfQueue;
    first = other.first;
    last = other.last;
    other.SizeOfQueue = 0;
    other.first = nullptr;
    other.last = nullptr;
  }
  return *this;
}

template <typename T>
void queue<T>::push(const_reference value) {
  typename s21::list<value_type>::Node* newNode =
      new typename s21::list<value_type>::Node(value);
  if (size() == 0) {
    first = last = newNode;
  } else {
    last->next = newNode;
    last = newNode;
  }
  SizeOfQueue++;
}

template <typename T>
void queue<T>::pop() {
  if (size() == 1) {
    delete last;
    first = nullptr;
    last = nullptr;
    SizeOfQueue--;
  } else if (size() > 1 && last != nullptr) {
    typename s21::list<value_type>::Node* temp = first;
    first = first->next;
    delete temp;
    SizeOfQueue--;
  };
}

template <typename T>
void queue<T>::swap(queue<T>& other) {
  // Меняем местами указатели на головы стеков
  typename s21::list<value_type>::Node* tempLast = last;
  last = other.last;
  other.last = tempLast;

  typename s21::list<value_type>::Node* tempFirst = first;
  first = other.first;
  other.first = tempFirst;

  // Меняем местами размеры стеков
  size_type tempSize = SizeOfQueue;
  SizeOfQueue = other.SizeOfQueue;
  other.SizeOfQueue = tempSize;
}

template <typename T>
void queue<T>::clean() {
  while (SizeOfQueue) {
    pop();
  }
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() {
  if (last != nullptr) {
    return last->value;
  }
  throw std::out_of_range("queue is empty");
}

template <typename T>
typename queue<T>::const_reference queue<T>::front() {
  if (first != nullptr) {
    return first->value;
  }
  throw std::out_of_range("queue is empty");
}

template <typename T>
bool queue<T>::empty() {
  return SizeOfQueue == 0;
}

template <typename T>
typename queue<T>::size_type queue<T>::size() {
  return SizeOfQueue;
};

}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_QUEUE_TPP_