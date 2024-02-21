#pragma once

#ifndef CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_LIST_H_
#define CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_LIST_H_

#include <cstddef>
#include <initializer_list>

namespace s21 {
template <typename T>
class list {
  using ValueType = T;
  using Reference = T&;
  using ConstReference = const T&;
  using SizeType = size_t;
  using DifferenceType = std::ptrdiff_t;

 public:
  struct Node {
    T value;
    Node* next;
    Node* prev;
    Node(T val, Node* nxt = nullptr, Node* prv = nullptr) noexcept
        : value(val), next(nxt), prev(prv) {}
  };

 public:
  class ConstIterator {
   public:
    ConstIterator(Node* ptr = nullptr) : ptr_(ptr) {}
    ConstIterator(const ConstIterator& other) : ptr_(other.ptr_) {}
    ConstIterator(ConstIterator&& other) noexcept : ptr_(other.ptr_) {
      other.ptr_ = nullptr;
    }
    ~ConstIterator() = default;

    ConstIterator operator+(DifferenceType n) const;
    ConstIterator operator-(DifferenceType n) const;

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

    Node* GetNode() const noexcept;

   protected:
    Node* ptr_;
  };

  class Iterator : public ConstIterator {
   public:
    Iterator(Node* ptr = nullptr) : ConstIterator(ptr){};
    Iterator(const Iterator& other) : ConstIterator(other){};
    Iterator(Iterator&& other) noexcept : ConstIterator(other){};
    ~Iterator() = default;

    Reference operator*();
  };

 public:
  list() noexcept;
  explicit list(SizeType size, const ValueType& value = ValueType()) noexcept;
  list(std::initializer_list<ValueType> const& objects) noexcept;
  list(const list& other);
  list(list&& other) noexcept;
  ~list();

  list& operator=(const list& other);
  list& operator=(list&& other) noexcept;

  void Resize(SizeType count, ValueType value = ValueType());
  bool IsEmpty() const noexcept;
  SizeType GetSize() const noexcept;

  Iterator Insert(ConstIterator iterator, const ValueType& value);
  void Remove(ConstReference value);

  void Erase(ConstIterator iterator_begin);
  void Erase(ConstIterator iterator_begin, ConstIterator iterator_end);

  ValueType& Front();
  ValueType& Back();

  ConstIterator CBegin() const noexcept;
  ConstIterator CEnd() const noexcept;

  Iterator Begin() noexcept;
  Iterator End() noexcept;

  void PushBack(ConstReference value);
  void PopBack();
  void PushFront(ConstReference value);
  void PopFront();

  void Sort();
  void Unique();
  void Reverse();
  void Clear();

  void Splice(ConstIterator pos, list& other);
  void Swap(list& other);
  void Merge(list& other);

  template <typename... Args>
  Iterator InsertMany(ConstIterator pos, Args&&... args);

  template <typename... Args>
  void InsertManyToBack(Args&&... args);

  template <typename... Args>
  void InsertManyToFront(Args&&... args);

 private:
  Node* head_;
  Node* tail_;
  SizeType size_;
};

}  // namespace s21

#include "../functions/s21_list.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_LIST_H_
