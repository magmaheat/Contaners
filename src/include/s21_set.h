#ifndef CPP2_S21_CONTAINERS_1_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_S21_SET_H_
#include "s21_rb_trees.h"

namespace s21 {
template <typename Key>
class set : public red_black_tree<Key, Key> {
public:
  using iterator = typename red_black_tree<Key, Key>::iterator;
  set() : red_black_tree<Key, Key>() {}
  set(std::initializer_list<Key> initList) {
      this->root_ = nullptr;
      for (const auto &item : initList) {
        this->insert_local(item);
      }
      this->init_conductor();
    }

  set(const set &other) noexcept : red_black_tree<Key, Key>(other) {
    if (this != &other) {
      this->root_ = nullptr;
      this->add(other.root_);
      this->conductor = other.conductor;
    }

  }

  set(set &&other) noexcept : red_black_tree<Key, Key>(other) {
    if (this != &other) {
      this->root_ = other.root_;
      other.root_ = nullptr;
      this->conductor = other.conductor;
      delete other.conductor;
      other.conductor = nullptr;
    }
  }

  ~set() {
    if (this->root_ != nullptr) {
      this->free(this->root_);
      this->root_ = nullptr;
    }
  }


//
//  typedef struct Node {
//    Key key;
//    Key data;
//    size_t count;
//    int replay;
////      Trees *grand;
//    Node *parent;
//    Node *left;
//    Node *right;
//    int color;
//  } Node;



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

  iterator begin() { return iterator (this->min(), this); }
  iterator end() {
    if (this->conductor) {
      this->conductor->parent = this->max();
    }
    return iterator(this->conductor, this);
  }


private:
  int get_mode() const override{
    return 1;
  }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_S21_SET_H_
