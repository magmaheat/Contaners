#ifndef S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_TPP_
#define S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_TPP_

// #include "../include/s21_stack.h"
namespace s21 {

template <typename T>
stack<T>::stack() {
  SizeOfStack = 0;
  head = nullptr;
}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const& items)
    : SizeOfStack(0), head(nullptr) {
  for (const auto& item : items) {
    push(item);
  }
}

template <typename T>
stack<T>::stack(const stack& s) : SizeOfStack(0), head(nullptr) {
  typename s21::list<T>::Node* current = s.head;
  while (current != nullptr) {
    push(current->value);
    current = current->next;
  }
}

template <typename T>
stack<T>::stack(stack&& s) : SizeOfStack(s.SizeOfStack), head(s.head) {
  s.SizeOfStack = 0;
  s.head = nullptr;
}

template <typename T>
stack<T>::~stack() {
  clean();
}

template <typename T>
stack<T> stack<T>::operator=(stack<T>&& other) {
  if (this != std::addressof(other)) {
    clean();
    SizeOfStack = other.SizeOfStack;
    head = other.head;
    other.SizeOfStack = 0;
    other.head = nullptr;
  }
  return *this;
}

template <typename T>
stack<T> stack<T>::operator=(const stack<T>& other) {
  if (this != std::addressof(other)) {
    clean();
    typename s21::list<T>::Node* current = other.head;
    while (current != nullptr) {
      push(current->value);
      current = current->next;
    }
  }
  return *this;
}

template <typename T>
void stack<T>::push(const_reference value) {
  if (head == nullptr) {
    head = new typename s21::list<T>::Node(value);
  } else {
    typename s21::list<T>::Node* current =
        new typename s21::list<T>::Node(value);
    current->next = head;
    head = current;
  }
  SizeOfStack++;
}

template <typename T>
void stack<T>::pop() {
  if (size() == 1) {
    delete head;
    head = nullptr;
    SizeOfStack--;
  } else if (size() > 1 && head != nullptr) {
    typename s21::list<T>::Node* temp = head;
    head = head->next;
    delete temp;
    SizeOfStack--;
  };
}

template <typename T>
void stack<T>::swap(stack<T>& other) {
  // Меняем местами указатели на головы стеков
  typename s21::list<T>::Node* temp = head;
  head = other.head;
  other.head = temp;

  // Меняем местами размеры стеков
  size_type tempSize = SizeOfStack;
  SizeOfStack = other.SizeOfStack;
  other.SizeOfStack = tempSize;
}

template <typename T>
void stack<T>::clean() {
  while (SizeOfStack) {
    pop();
  }
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() {
  if (head != nullptr) {
    return head->value;
  }
  throw std::out_of_range("Stack is empty");
}

template <typename T>
bool stack<T>::empty() {
  return SizeOfStack == 0;
}

template <typename T>
typename stack<T>::size_type stack<T>::size() {
  return SizeOfStack;
};

}  // namespace s21

#endif  // S21_CPP_S21_CONTAINERS_SRC_S21_CONTAINERS_S21_STACK_TPP_