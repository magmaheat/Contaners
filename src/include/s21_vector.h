#pragma once

#ifndef CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_VECTOR_H_
#define CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_VECTOR_H_

#include <cstddef>
#include <initializer_list>

namespace s21 {
template <typename T>
class vector {
  using ValueType = T;
  using Reference = T&;
  using ConstReference = const T&;
  using SizeType = size_t;
  using DifferenceType = std::ptrdiff_t;

 public:
  class ConstIterator {
   public:
    ConstIterator(ValueType* ptr = nullptr) : ptr_(ptr) {}
    ConstIterator(const ConstIterator& other) : ptr_(other.ptr_) {}
    ConstIterator(ConstIterator&& other) noexcept : ptr_(other.ptr_) {
      other.ptr_ = nullptr;
    }
    ~ConstIterator() = default;

    ConstIterator operator+(DifferenceType n) const;
    DifferenceType operator+(const ConstIterator& other) const;
    ConstIterator operator-(DifferenceType n) const;
    DifferenceType operator-(const ConstIterator& other) const;

    ConstIterator& operator++();
    ConstIterator& operator--();
    ConstIterator operator++(int);
    ConstIterator operator--(int);

    ConstReference operator*() const;

    ConstIterator& operator+=(SizeType n);
    ConstIterator& operator-=(SizeType n);
    ConstIterator& operator=(const ConstIterator& other);

    bool operator==(const ConstIterator& other) const;
    bool operator!=(const ConstIterator& other) const;

    bool operator<(const ConstIterator& other) const;
    bool operator>(const ConstIterator& other) const;
    bool operator<=(const ConstIterator& other) const;
    bool operator>=(const ConstIterator& other) const;

   protected:
    ValueType* ptr_;
  };

  class Iterator : public ConstIterator {
   public:
    Iterator(ValueType* ptr = nullptr) : ConstIterator(ptr){};
    Iterator(const Iterator& other) : ConstIterator(other){};
    Iterator(Iterator&& other) noexcept : ConstIterator(other){};
    ~Iterator() = default;

    Reference operator*();
  };

 public:
  vector() noexcept;
  explicit vector(SizeType size, const ValueType& value = ValueType());
  vector(std::initializer_list<ValueType> const& items) noexcept;
  vector(const vector& other);
  vector(vector&& other) noexcept;
  ~vector();

  vector& operator=(const vector& other);
  vector& operator=(vector&& other) noexcept;

  Reference operator[](SizeType pos);
  Reference At(SizeType pos);

  bool IsEmpty() const noexcept;

  SizeType Capacity();
  SizeType GetSize() const noexcept;
  SizeType GetMaxSize() const noexcept;

  Iterator Insert(ConstIterator iterator, const ValueType& value);

  void Erase(ConstIterator iterator_begin);

  ConstReference Front();
  ConstReference Back();

  ValueType* data();

  ConstIterator CBegin() const noexcept;
  ConstIterator CEnd() const noexcept;

  Iterator Begin() noexcept;
  Iterator End() noexcept;

  void PushBack(ConstReference value);
  void PopBack();

  void Clear();
  void Reserve(SizeType size);
  void ShrinkToFit();
  void Swap(vector& other);

  template <typename... Args>
  Iterator InsertMany(ConstIterator pos, Args&&... args);

  template <typename... Args>
  void InsertManyToBack(Args&&... args);

 private:
  ValueType* data_;
  SizeType size_;
  SizeType capacity_;
};
}  // namespace s21

#include "../functions/s21_vector.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_VECTOR_H_
