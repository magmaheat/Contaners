#ifndef CPP2_S21_CONTAINERS_1_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_S21_SET_H_
#include "s21_rb_trees.h"

namespace s21 {
template <typename Key>
class set : public red_black_tree<Key, Key> {
public:
  using iterator = typename red_black_tree<Key, Key>::iterator;
  set() : red_black_tree<Key, Key>() {}
  set(std::initializer_list<Key> initList) : red_black_tree<Key, Key>(initList) {}
  set(const set &other) : red_black_tree<Key, Key>(other) {}
  set(set &&other) noexcept : red_black_tree<Key, Key>(std::move(other)) {}
  ~set() = default;

  set<Key> &operator=(set<Key> &&other) noexcept {
    red_black_tree<Key, Key>::operator=(std::move(other));
    return *this;
  }

  set<Key> &operator=(const set<Key> &other) noexcept {
    red_black_tree<Key, Key>::operator=(other);
    return *this;
  }

  std::pair<iterator, bool>insert(const Key& value) {
    std::pair<typename red_black_tree<Key, Key>::Node*, bool> return_insert = this->insert_local(value);
    return std::pair<iterator, bool>(iterator(return_insert.first, this), return_insert.second);
  }

  iterator find(const Key &value) {
    return iterator(this->find_local(value), this);
  }

  iterator begin() { return iterator (this->min(this->root), this); }
  iterator end() {return iterator(nullptr, this);}

  template<typename ...Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    std::vector<std::pair<iterator, bool>> result;
    (result.push_back(insert(std::forward<Args>(args))), ...);

    return result;
  }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_S21_SET_H_
