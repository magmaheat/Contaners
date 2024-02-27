#pragma once

#include "s21_rb_trees.h"

namespace s21 {
template <typename Key>
class multiset : public red_black_tree<Key, Key> {
public:
  using iterator = typename red_black_tree<Key, Key>::iterator;

  multiset() : red_black_tree<Key, Key>() {}
  multiset(std::initializer_list<Key> initList) {
    for (const auto &item: initList) {
      this->insert_local(item, item,2);
    }
  }

  multiset(const multiset &other) : red_black_tree<Key, Key>() {
    this->add(other.root);
  }

  multiset(multiset &&other) noexcept : red_black_tree<Key, Key>(std::move(other)) {}
  ~multiset() = default;

  multiset<Key> &operator=(multiset<Key> &&other) noexcept {
    if (this != &other) {
      red_black_tree<Key, Key>::operator=(std::move(other));
    }
    return *this;
  }

  multiset<Key> &operator=(const multiset<Key> &other) noexcept {
    red_black_tree<Key, Key>::operator=(other);
    return *this;
  }

  iterator insert(const Key& value) {
    return iterator(this->insert_local(value, value, 2).first, this);
  }

  template<typename ...Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.push_back(std::pair(insert(std::forward<Args>(args)), true)), ...);

    return result;
  }

  iterator find(const Key &value) {
    return iterator(this->find_local(value), this);
  }

  size_t count(const Key& key) { return this->count_elem(key); }

  std::pair<iterator, iterator> equal_range(const Key& key){
    iterator begin_it(this->find(key));
    iterator end_it = begin_it;
    iterator end_copy = end_it;
    if (begin_it != this->end()) {
      while (end_it == end_copy) {
        end_it++;
      }
    }
    std::pair<iterator, iterator> result(begin_it, end_it);

    return result;
  }

  void merge(multiset<Key> &other) {
    if (this != &other && other.root != nullptr) {
      iterator it = other.tree_begin();
      while (it != other.end()) {
        this->insert_local(*it, *it, 2);
        it++;
      }

      this->free(other.root);
      other.root = nullptr;
      other.count_element = 0;
    }
  }

  iterator lower_bound(const Key& key) {
    iterator result = this->begin();
    while (result != this->end() && *result < key) {
      result++;
    }
    return result;
  }

  iterator upper_bound(const Key& key) {
    iterator result = lower_bound(key);
    while (result != this->end() && *result == key) {
      result++;
    }
    return result;
  }

  iterator begin() { return iterator (this->min(this->root), this); }
  iterator end() {return iterator(nullptr, this);}
};
}  // namespace s21
