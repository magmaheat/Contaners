#ifndef CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_VECTOR_TPP_
#define CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_VECTOR_TPP_

#include <cstddef>
#include <stdexcept>

namespace s21 {

// ---------------------------------------
// VECTOR IMPLEMENTATION
// ---------------------------------------

template <typename T>
vector<T>::vector() noexcept : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
vector<T>::vector(SizeType size, const ValueType& value) {
  if (size > std::numeric_limits<SizeType>::max() / sizeof(ValueType)) {
    throw std::length_error("|| ERROR || Size is too large");
  }
  data_ = new ValueType[size];
  size_ = size;
  capacity_ = size;
  std::fill(data_, data_ + size_, value);
}

template <typename T>
vector<T>::vector(std::initializer_list<ValueType> const& items) noexcept
    : data_(new ValueType[items.size()]),
      size_(items.size()),
      capacity_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
vector<T>::vector(const vector& other)
    : data_(new ValueType[other.capacity_]),
      size_(other.size_),
      capacity_(other.capacity_) {
  std::copy(other.data_, other.data_ + size_, data_);
}

template <typename T>
vector<T>::vector(vector&& other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename T>
vector<T>::~vector() {
  delete[] data_;
}

template <typename T>
vector<T>& vector<T>::operator=(const vector& other) {
  if (this != &other) {
    delete[] data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = new ValueType[capacity_];
    std::copy(other.data_, other.data_ + size_, data_);
  }
  return *this;
}

template <typename T>
vector<T>& vector<T>::operator=(vector&& other) noexcept {
  if (this != &other) {
    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  return *this;
}

template <typename T>
typename vector<T>::Reference vector<T>::operator[](SizeType pos) {
  if (pos >= size_) {
    throw std::out_of_range("|| ERROR || Index out of range in operator[]");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::Reference vector<T>::At(SizeType pos) {
  if (pos >= size_) {
    throw std::out_of_range("|| ERROR || Index out of range");
  }
  return data_[pos];
}

template <typename T>
bool vector<T>::IsEmpty() const noexcept {
  return size_ == 0;
}

template <typename T>
typename vector<T>::SizeType vector<T>::Capacity() {
  return capacity_;
}

template <typename T>
typename vector<T>::SizeType vector<T>::GetSize() const noexcept {
  return size_;
}

template <typename T>
typename vector<T>::SizeType vector<T>::GetMaxSize() const noexcept {
  return std::numeric_limits<SizeType>::max() / sizeof(ValueType);
}

template <typename T>
typename vector<T>::Iterator vector<T>::Insert(ConstIterator iterator,
                                               const ValueType& value) {
  if (iterator < CBegin() || iterator > CEnd()) {
    throw std::out_of_range(
        "|| ERROR || Iterator is out of range for Insert operation.");
  }

  SizeType pos = iterator - CBegin();
  if (size_ >= capacity_) {
    Reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  for (SizeType i = size_; i > pos; --i) {
    data_[i] = data_[i - 1];
  }
  data_[pos] = value;
  ++size_;
  return Iterator(data_ + pos);
}

template <typename T>
void vector<T>::Erase(ConstIterator iterator_begin) {
  if (iterator_begin < CBegin() || iterator_begin >= CEnd()) {
    throw std::out_of_range("|| ERROR || Iterator is out of range.");
  }

  if (iterator_begin == CEnd()) {
    throw std::out_of_range("|| ERROR || Cannot erase end iterator.");
  }

  if (iterator_begin != CEnd()) {
    SizeType pos = iterator_begin - CBegin();
    for (SizeType i = pos; i < size_ - 1; ++i) {
      data_[i] = data_[i + 1];
    }
    --size_;
  }
}

template <typename T>
typename vector<T>::ValueType* vector<T>::data() {
  return data_;
}

template <typename T>
typename vector<T>::ConstReference vector<T>::Front() {
  if (IsEmpty())
    throw std::out_of_range("|| ERROR || Vector is empty");
  return data_[0];
}

template <typename T>
typename vector<T>::ConstReference vector<T>::Back() {
  if (IsEmpty())
    throw std::out_of_range("|| ERROR || Vector is empty");
  return data_[size_ - 1];
}

template <typename T>
typename vector<T>::ConstIterator vector<T>::CBegin() const noexcept {
  return ConstIterator(data_);
}

template <typename T>
typename vector<T>::ConstIterator vector<T>::CEnd() const noexcept {
  return ConstIterator(data_ + size_);
}

template <typename T>
typename vector<T>::Iterator vector<T>::Begin() noexcept {
  return Iterator(data_);
}

template <typename T>
typename vector<T>::Iterator vector<T>::End() noexcept {
  return Iterator(data_ + size_);
}

template <typename T>
void vector<T>::PushBack(ConstReference value) {
  if (size_ == capacity_) {
    Reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  data_[size_++] = value;
}

template <typename T>
void vector<T>::PopBack() {
  if (size_ > 0) {
    --size_;
  }
}

template <typename T>
void vector<T>::Clear() {
  size_ = 0;
}

template <typename T>
void vector<T>::Reserve(SizeType new_capacity) {
  if (new_capacity > std::numeric_limits<SizeType>::max() / sizeof(ValueType)) {
    throw std::length_error("|| ERROR || Size is too large");
  }

  if (new_capacity > capacity_) {
    ValueType* new_data = new ValueType[new_capacity];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
}

template <typename T>
void vector<T>::ShrinkToFit() {
  if (size_ < capacity_) {
    ValueType* new_data = new ValueType[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::Swap(vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
template <typename... Args>
typename vector<T>::Iterator vector<T>::InsertMany(ConstIterator pos,
                                                   Args&&... args) {
  SizeType numNewElements = sizeof...(args);
  SizeType insertPos = pos - CBegin();
  if (size_ + numNewElements > capacity_) {
    Reserve(std::max(capacity_ * 2, size_ + numNewElements));
  }
  if (insertPos < size_) {
    for (SizeType i = size_; i-- > insertPos;) {
      data_[i + numNewElements] = std::move(data_[i]);
    }
  }
  auto inserter = [&](auto&& arg) {
    data_[insertPos++] = std::forward<decltype(arg)>(arg);
  };
  (..., inserter(args));
  size_ += numNewElements;
  return Iterator(data_ + insertPos - numNewElements);
}

template <typename T>
template <typename... Args>
void vector<T>::InsertManyToBack(Args&&... args) {
  (..., PushBack(args));
}

// ---------------------------------------
// CONST ITERATOR IMPLEMENTATION
// ---------------------------------------

template <typename T>
typename vector<T>::ConstIterator vector<T>::ConstIterator::operator+(
    DifferenceType n) const {
  return ConstIterator(ptr_ + n);
}

template <typename T>
typename vector<T>::ConstIterator vector<T>::ConstIterator::operator-(
    DifferenceType n) const {
  return ConstIterator(ptr_ - n);
}

template <typename T>
typename vector<T>::DifferenceType vector<T>::ConstIterator::operator-(
    const ConstIterator& other) const {
  return ptr_ - other.ptr_;
}

template <typename T>
typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator++() {
  ++ptr_;
  return *this;
}

template <typename T>
typename vector<T>::ConstIterator vector<T>::ConstIterator::operator++(int) {
  ConstIterator temp = *this;
  ++(*this);
  return temp;
}

template <typename T>
typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator--() {
  --ptr_;
  return *this;
}

template <typename T>
typename vector<T>::ConstIterator vector<T>::ConstIterator::operator--(int) {
  ConstIterator temp = *this;
  --(*this);
  return temp;
}

template <typename T>
typename vector<T>::ConstReference vector<T>::ConstIterator::operator*() const {
  return *ptr_;
}

template <typename T>
typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator+=(
    SizeType n) {
  ptr_ += n;
  return *this;
}

template <typename T>
typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator-=(
    SizeType n) {
  ptr_ -= n;
  return *this;
}

template <typename T>
typename vector<T>::ConstIterator& vector<T>::ConstIterator::operator=(
    const ConstIterator& other) {
  if (this != &other) {
    ptr_ = other.ptr_;
  }
  return *this;
}

template <typename T>
bool vector<T>::ConstIterator::operator==(const ConstIterator& other) const {
  return ptr_ == other.ptr_;
}

template <typename T>
bool vector<T>::ConstIterator::operator!=(const ConstIterator& other) const {
  return ptr_ != other.ptr_;
}

template <typename T>
bool vector<T>::ConstIterator::operator<(const ConstIterator& other) const {
  return ptr_ < other.ptr_;
}

template <typename T>
bool vector<T>::ConstIterator::operator>(const ConstIterator& other) const {
  return ptr_ > other.ptr_;
}

template <typename T>
bool vector<T>::ConstIterator::operator<=(const ConstIterator& other) const {
  return ptr_ <= other.ptr_;
}

template <typename T>
bool vector<T>::ConstIterator::operator>=(const ConstIterator& other) const {
  return ptr_ >= other.ptr_;
}

// ---------------------------------------
// ITERATOR IMPLEMENTATION
// ---------------------------------------

template <typename T>
typename vector<T>::Reference vector<T>::Iterator::operator*() {
  return *this->ptr_;
}

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_VECTOR_TPP_