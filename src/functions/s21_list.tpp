#ifndef CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_LIST_TPP_
#define CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_LIST_TPP_

#include <cstddef>
#include <stdexcept>

namespace s21 {

// ---------------------------------------
// LIST IMPLEMENTATION
// ---------------------------------------

template <typename T>
list<T>::list() noexcept : head_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
list<T>::list(SizeType size, const ValueType& value) noexcept : list() {
  while (size > 0) {
    PushBack(value);
    --size;
  }
}

template <typename T>
list<T>::list(std::initializer_list<ValueType> const& objects) noexcept
    : list() {
  for (const T& value : objects) {
    PushBack(value);
  }
}

template <typename T>
list<T>::~list() {
  while (head_ != nullptr) {
    Node* current = head_;
    head_ = head_->next;
    delete current;
  }
}

template <typename T>
list<T>::list(const list& other) : list() {
  for (Node* node = other.head_; node != nullptr; node = node->next) {
    PushBack(node->value);
  }
}

template <typename T>
list<T>::list(list&& other) noexcept
    : head_(other.head_), tail_(other.tail_), size_(other.size_) {
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

template <typename T>
list<T>& list<T>::operator=(const list<T>& other) {
  if (this != &other) {
    while (!IsEmpty()) {
      PopBack();
    }
    for (Node* node = other.head_; node != nullptr; node = node->next) {
      PushBack(node->value);
    }
  }
  return *this;
}

template <typename T>
list<T>& list<T>::operator=(list<T>&& other) noexcept {
  if (this != &other) {
    while (!IsEmpty()) {
      PopBack();
    }
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
void list<T>::Splice(ConstIterator pos, list& other) {
  if (this == &other) {
    return;
  }

  if (!other.IsEmpty()) {
    Node* posNode = pos.GetNode();

    if (posNode != nullptr) {
      if (posNode->prev != nullptr) {
        posNode->prev->next = other.head_;
      } else {
        head_ = other.head_;
      }
      if (other.head_ != nullptr) {
        other.head_->prev = posNode->prev;
      }
      if (other.tail_ != nullptr) {
        other.tail_->next = posNode;
      }
      if (posNode != nullptr) {
        posNode->prev = other.tail_;
      }
    } else {
      if (tail_ != nullptr) {
        tail_->next = other.head_;
        other.head_->prev = tail_;
      } else {
        head_ = other.head_;
      }
      tail_ = other.tail_;
    }

    size_ += other.size_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
}

template <typename T>
void list<T>::Swap(list& other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <typename T>
void list<T>::Merge(list& other) {
  if (this != &other) {
    Iterator it = Begin();
    while (!other.IsEmpty() && it != End()) {
      if (other.Front() < *it) {
        Insert(it, other.Front());
        other.PopFront();
      } else {
        ++it;
      }
    }
    Splice(End(), other);
  }
}

template <typename T>
void list<T>::PushBack(ConstReference value) {
  Node* newNode = new Node(value);
  newNode->next = nullptr;
  newNode->prev = tail_;
  if (tail_ != nullptr) {
    tail_->next = newNode;
  } else {
    head_ = newNode;
  }
  tail_ = newNode;
  ++size_;
}

template <typename T>
void list<T>::PushFront(ConstReference value) {
  Node* newNode = new Node(value);
  if (head_ == nullptr) {
    head_ = newNode;
    tail_ = newNode;
  } else {
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
  }
  ++size_;
}

template <typename T>
void list<T>::PopBack() {
  if (tail_ != nullptr) {
    Node* toDelete = tail_;
    tail_ = tail_->prev;
    if (tail_ != nullptr) {
      tail_->next = nullptr;
    } else {
      head_ = nullptr;
    }
    delete toDelete;
    --size_;
  }
}

template <typename T>
void list<T>::PopFront() {
  if (head_ != nullptr) {
    Node* toDelete = head_;
    head_ = head_->next;
    if (head_ != nullptr) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
    delete toDelete;
    --size_;
  }
}

template <typename T>
void list<T>::Erase(ConstIterator iterator) {
  if (iterator.GetNode() == nullptr || iterator == End()) {
    throw std::out_of_range(
        "|| ERROR || Cannot erase end or invalid iterator.");
  }

  Node* toDelete = iterator.GetNode();
  if (toDelete->prev != nullptr) {
    toDelete->prev->next = toDelete->next;
  } else {
    head_ = toDelete->next;
  }
  if (toDelete->next != nullptr) {
    toDelete->next->prev = toDelete->prev;
  } else {
    tail_ = toDelete->prev;
  }
  delete toDelete;
  --size_;
}

template <typename T>
void list<T>::Erase(ConstIterator iterator_begin, ConstIterator iterator_end) {
  while (iterator_begin != iterator_end) {
    Node* current = iterator_begin.GetNode();
    ++iterator_begin;
    if (current->prev != nullptr) {
      current->prev->next = current->next;
    } else {
      head_ = current->next;
    }
    if (current->next != nullptr) {
      current->next->prev = current->prev;
    } else {
      tail_ = current->prev;
    }
    delete current;
    --size_;
  }
}

template <typename T>
void list<T>::Sort() {
  if (head_ != nullptr && head_->next != nullptr) {
    for (Node* it = head_->next; it != nullptr; it = it->next) {
      ValueType value = it->value;
      Node* j = it;
      while (j->prev != nullptr && j->prev->value > value) {
        j->value = j->prev->value;
        j = j->prev;
      }
      j->value = value;
    }
  }
}

template <typename T>
void list<T>::Reverse() {
  Node* current = head_;
  Node* temp = nullptr;
  while (current != nullptr) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }
  if (temp != nullptr) {
    head_ = temp->prev;
  }
}

template <typename T>
void list<T>::Clear() {
  while (!IsEmpty()) {
    PopFront();
  }
}

template <typename T>
template <typename... Args>
typename list<T>::Iterator list<T>::InsertMany(ConstIterator pos,
                                               Args&&... args) {
  (Insert(pos, std::forward<Args>(args)), ...);
  return Iterator(pos.GetNode());
}

template <typename T>
template <typename... Args>
void list<T>::InsertManyToBack(Args&&... args) {
  (PushBack(std::forward<Args>(args)), ...);
}

template <typename T>
template <typename... Args>
void list<T>::InsertManyToFront(Args&&... args) {
  (PushFront(std::forward<Args>(args)), ...);
}

template <typename T>
typename list<T>::Iterator list<T>::Insert(ConstIterator iterator,
                                           const ValueType& value) {
  Node* newNode = new Node(value);
  Node* current = iterator.GetNode();

  if (head_ == nullptr || current == head_) {
    newNode->next = head_;
    if (head_ != nullptr) {
      head_->prev = newNode;
    }
    head_ = newNode;
    if (tail_ == nullptr) {
      tail_ = newNode;
    }
  } else if (current == nullptr) {
    newNode->prev = tail_;
    if (tail_ != nullptr) {
      tail_->next = newNode;
    }
    tail_ = newNode;
  } else {
    newNode->prev = current->prev;
    newNode->next = current;
    if (current->prev != nullptr) {
      current->prev->next = newNode;
    }
    current->prev = newNode;
  }

  ++size_;
  return Iterator(newNode);
}

template <typename T>
void list<T>::Remove(ConstReference value) {
  Node* current = head_;
  while (current != nullptr) {
    if (current->value == value) {
      Node* toDelete = current;

      if (current->prev != nullptr) {
        current->prev->next = current->next;
      } else {
        head_ = current->next;
      }

      if (current->next != nullptr) {
        current->next->prev = current->prev;
      } else {
        tail_ = current->prev;
      }

      current = current->next;

      delete toDelete;
      --size_;
    } else {
      current = current->next;
    }
  }
}

template <typename T>
void list<T>::Unique() {
  if (head_ == nullptr)
    return;

  Node* current = head_;
  while (current != nullptr && current->next != nullptr) {
    if (current->value == current->next->value) {
      Node* toDelete = current->next;
      current->next = toDelete->next;
      if (toDelete->next != nullptr)
        toDelete->next->prev = current;
      delete toDelete;
      --size_;
    } else {
      current = current->next;
    }
  }
}

template <typename T>
typename list<T>::ValueType& list<T>::Front() {
  if (head_ == nullptr) {
    throw std::out_of_range("|| ERROR || List is empty");
  }
  return head_->value;
}

template <typename T>
typename list<T>::ValueType& list<T>::Back() {
  if (tail_ == nullptr) {
    throw std::out_of_range("|| ERROR || List is empty");
  }
  return tail_->value;
}

template <typename T>
void list<T>::Resize(SizeType count, ValueType value) {
  if (size_ > count) {
    while (size_ > count) {
      PopBack();
    }
  } else {
    while (size_ < count) {
      PushBack(value);
    }
  }
}

template <typename T>
bool list<T>::IsEmpty() const noexcept {
  return size_ == 0;
}

template <typename T>
typename list<T>::SizeType list<T>::GetSize() const noexcept {
  return size_;
}

template <typename T>
typename list<T>::ConstIterator list<T>::CBegin() const noexcept {
  return ConstIterator(head_);
}

template <typename T>
typename list<T>::ConstIterator list<T>::CEnd() const noexcept {
  return ConstIterator(nullptr);
}

template <typename T>
typename list<T>::Iterator list<T>::Begin() noexcept {
  return Iterator(head_);
}

template <typename T>
typename list<T>::Iterator list<T>::End() noexcept {
  return Iterator(nullptr);
}

// ---------------------------------------
// CONST ITERATOR IMPLEMENTATION
// ---------------------------------------

template <typename T>
typename list<T>::ConstIterator& list<T>::ConstIterator::operator=(
    const ConstIterator& other) {
  ptr_ = other.ptr_;
  return *this;
}

template <typename T>
typename list<T>::ConstReference list<T>::ConstIterator::operator*() const {
  if (ptr_ == nullptr) {
    throw std::out_of_range(
        "|| ERROR || Iterator cannot dereference null pointer");
  }
  return ptr_->value;
}

template <typename T>
typename list<T>::ConstIterator& list<T>::ConstIterator::operator+=(
    SizeType n) {
  while (n > 0) {
    ++(*this);
    --n;
  }
  return *this;
}

template <typename T>
typename list<T>::ConstIterator& list<T>::ConstIterator::operator-=(
    SizeType n) {
  while (n > 0) {
    --(*this);
    --n;
  }
  return *this;
}

template <typename T>
typename list<T>::ConstIterator& list<T>::ConstIterator::operator++() {
  if (ptr_ != nullptr) {
    ptr_ = ptr_->next;
  } else {
    throw std::out_of_range(
        "|| ERROR || Iterator cannot be incremented past the end");
  }
  return *this;
}

template <typename T>
typename list<T>::ConstIterator& list<T>::ConstIterator::operator--() {
  if (ptr_ != nullptr) {
    ptr_ = ptr_->prev;
  } else {
    throw std::out_of_range(
        "|| ERROR || Iterator cannot be reduced beyond the beginning");
  }
  return *this;
}

template <typename T>
typename list<T>::ConstIterator list<T>::ConstIterator::operator++(int) {
  ConstIterator temp(*this);
  if (ptr_ != nullptr) {
    ptr_ = ptr_->next;
  } else {
    throw std::out_of_range(
        "|| ERROR || Iterator cannot be incremented past the end");
  }
  return temp;
}

template <typename T>
typename list<T>::ConstIterator list<T>::ConstIterator::operator--(int) {
  ConstIterator temp(*this);
  if (ptr_ != nullptr) {
    ptr_ = ptr_->prev;
  } else {
    throw std::out_of_range(
        "|| ERROR || Iterator cannot be reduced beyond the beginning");
  }
  return temp;
}

template <typename T>
typename list<T>::ConstIterator list<T>::ConstIterator::operator-(
    DifferenceType n) const {
  ConstIterator temp(*this);
  while (n > 0 && temp.ptr_ != nullptr) {
    temp.ptr_ = temp.ptr_->prev;
    --n;
  }
  if (n > 0) {
    throw std::out_of_range("|| ERROR || Iterator out of range");
  }
  return temp;
}

template <typename T>
bool list<T>::ConstIterator::operator==(const ConstIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool list<T>::ConstIterator::operator!=(const ConstIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
bool list<T>::ConstIterator::operator<(const ConstIterator& other) const {
  Node* temp = ptr_;
  while (temp != nullptr) {
    if (temp == other.ptr_)
      return true;
    temp = temp->next;
  }
  return false;
}

template <typename T>
bool list<T>::ConstIterator::operator>(const ConstIterator& other) const {
  return other < *this;
}

template <typename T>
bool list<T>::ConstIterator::operator<=(const ConstIterator& other) const {
  return !(*this > other);
}

template <typename T>
bool list<T>::ConstIterator::operator>=(const ConstIterator& other) const {
  return !(*this < other);
}

template <typename T>
typename list<T>::Node* list<T>::ConstIterator::GetNode() const noexcept {
  return ptr_;
}

// ---------------------------------------
// ITERATOR IMPLEMENTATION
// ---------------------------------------

template <typename T>
typename list<T>::Reference list<T>::Iterator::operator*() {
  if (this->ptr_ == nullptr) {
    throw std::out_of_range(
        "|| ERROR || Iterator cannot dereference null pointer");
  }
  return this->ptr_->value;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_LIST_TPP_