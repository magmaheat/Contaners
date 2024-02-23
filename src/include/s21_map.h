#ifndef CONTAINERS_S21_MAP_H
#define CONTAINERS_S21_MAP_H

#include "s21_rb_trees.h"

namespace s21 {
  template <typename Key, typename T>
  class map : public red_black_tree<Key, T> {
  public:
    using key_type = Key;
    using mapped_type = T;
    using value_type = std::pair<Key, T>;
    using tree = red_black_tree<key_type, mapped_type>;
    using map_temp = map<key_type, mapped_type>;

    map() : red_black_tree<key_type, mapped_type>() {};
    map(std::initializer_list<value_type> initList) {
      for (const auto &item: initList) {
        this->insert_local(item.first, item.second);
      }
    }

    map(const map &other) : red_black_tree<Key, T>() {
      this->add(other.root_);
    }

    map(map &&other) noexcept : red_black_tree<Key, T>(std::move(other)) {}
    ~map() = default;

    map<key_type, T> &operator=(map_temp &&other) noexcept {
      if (this != &other) {
        red_black_tree<key_type, key_type>::operator=(std::move(other));
      }
      return *this;
    }

    map<key_type, T> &operator=(const map_temp &other) {
      red_black_tree<Key, Key>::operator=(other);
      return *this;
    }

    class map_iterator : public tree::tree_iterator {
    public:
    using tree = red_black_tree<key_type, mapped_type>;

    map_iterator(typename red_black_tree<key_type, mapped_type>::Node* node,
                 red_black_tree<key_type, mapped_type>* tree_ref) :
                 tree::iterator(node, tree_ref) {
    }


    std::pair<const Key, T>* operator->() {
      return &this->current_->pair;
    }

    std::pair<const Key, T>& operator*() {
      return this->current_->pair;
    }

    typename tree::iterator& operator++() override {
    tree::iterator::operator++();
      return *this;
    }

    typename tree::iterator operator++(int) override {
      typename tree::iterator temp = *this;
      ++(*this);
      return temp;
    }

    typename tree::iterator& operator--() override {
      tree::iterator::operator++();
      return *this;
    }

    typename tree::iterator operator--(int) override {
      typename tree::iterator temp = *this;
      --(*this);
      return temp;
    }

    bool operator==(const typename tree::iterator &other) {
      typename tree::iterator temp = *this;
      return temp == other;
    }

    bool operator!=(const typename tree::iterator &other) {
      typename tree::iterator temp = *this;
      return temp != other;
    }
  };
    using iterator = map_iterator;

    iterator begin() {return iterator(this->min(this->root_), this);}
    iterator end() {return iterator(nullptr, this);}

    std::pair<iterator, bool>insert(const value_type& value) {
      std::pair<typename red_black_tree<Key, T>::Node*, bool> return_insert = this->insert_local(value.first, value.second);
      return std::pair<iterator, bool>(iterator(return_insert.first, this), return_insert.second);
    }

    std::pair<iterator, bool>insert(const key_type & key, const mapped_type& data) {
      std::pair<typename red_black_tree<Key, T>::Node*, bool> return_insert = this->insert_local(key, data);
      return std::pair<iterator, bool>(iterator(return_insert.first, this), return_insert.second);
    }

    std::pair<iterator, bool> insert_or_assign(const Key& key, const T& data) {
      mode_ = 4;
      std::pair<typename red_black_tree<Key, T>::Node*, bool> return_insert = this->insert_local(key, data);
      mode_ = 3;
      return std::pair<iterator, bool>(iterator(return_insert.first, this), return_insert.second);
    }

    template<typename ...Args>
    std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
      std::vector<std::pair<iterator, bool>> result;
      (result.push_back(insert(std::forward<Args>(args))), ...);

      return result;
    }

    T& at(const key_type& key) {
      return this->find_local(key)->data;
    }

    T& operator[](const key_type& key) {
      typename red_black_tree<Key, T>::Node* node = this->find_local(key);
      if (node == nullptr) {
        node = this->insert_local(key).first;
      }
      return node->data;
    }

  private:
    int mode_ = 3;
    int get_mode() const override{
      return mode_;
    }

  };
}

//#include "s21_map.tpp"

#endif //CONTAINERS_S21_MAP_H
