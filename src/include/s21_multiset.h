#ifndef CONTAINERS_S21_MULTISET_H
#define CONTAINERS_S21_MULTISET_H

#include "s21_rb_trees.h"

namespace s21 {
  template <typename Key>
  class multiset : public red_black_tree<Key, Key> {
  public:
    using iterator = typename red_black_tree<Key, Key>::iterator;

    multiset() : red_black_tree<Key, Key>() {}
    multiset(std::initializer_list<Key> initList) : red_black_tree<Key, Key>(initList){}
    multiset(const multiset &other) noexcept : red_black_tree<Key, Key>(other) {}
    multiset(multiset &&other) noexcept : red_black_tree<Key, Key>(other){}
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

  protected:
    iterator insert(const Key& value) {
      return this->insert_local(value).first;
    }

    iterator find(const Key &value) {
      return iterator(this->find_local(value), this);
    }

    size_t count(const Key& key) { return this->count_elem(this->find(key)); }

    std::pair<iterator, iterator> equal_range(const Key& key){
      iterator found(this->find(key));
      std::pair<iterator, iterator> result(found, found);

      return result;
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
      while (result != this->end() && *result != key) {
        result++;
      }
      return result;
    }

    iterator begin() { return iterator (this->min(), this); }
    iterator end() {return iterator(nullptr, this);}

  private:
    int get_mode() const override{
      return 2;
    }
  };
}

#endif //CONTAINERS_S21_MULTISET_H
