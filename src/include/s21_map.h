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
    using reference = value_type&;
    using const_reference = const value_type&;
    using tree = red_black_tree<key_type, mapped_type>;
//    using iterator = typename red_black_tree<Key, T>::iterator;
    using map_temp = map<key_type, mapped_type>;

    map() : red_black_tree<key_type, mapped_type>() {};
    map(std::initializer_list<value_type> initList) {
      this->root_ = nullptr;
      for (const auto &item : initList) {
        this->insert_local(item.first, item.second);
      }
      this->init_conductor();
    }

    map(const map &other) noexcept {
      this->root_ = nullptr;
      add(other.root);
      this->conductor = other.conductor;
    }

    map(map &&other) noexcept {
      if (this != &other) {
        this->root_ = other.root_;
        other.root_ = nullptr;
        this->conductor = other.conductor;
        delete other.conductor;
        other.conductor = nullptr;
      }
    }

    ~map() {
      if (this->root_ != nullptr) {
        free(this->root_);
        this->root_ = nullptr;
      }
    }

    map<key_type, T> &operator=(map<key_type, mapped_type> &&other) noexcept {
      if (this != &other) {
        red_black_tree<key_type, key_type>::operator=(std::move(other));
      }
      return *this;
    }

    map<key_type, T> &operator=(const map<key_type, T> &other) noexcept {
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
      if (this->current_) {
        return &this->current_->pair;
      } else {
        throw std::runtime_error("Iterator is not pointing to a node");
      }
    }

    std::pair<const Key, T>& operator*() {
      if (this->current_) {
        return this->current_->pair;
      } else {
        throw std::runtime_error("Iterator is not pointing to a node");
      }
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


    private:
  };
    using iterator = map_iterator;

    iterator begin() {return iterator(this->min(), this);}
    iterator end() {
      if (this->conductor) {
        this->conductor->parent = this->max();
      }
      return iterator(this->conductor, this);
    }

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

//    TODO спрятать лишние методы

  private:
    int mode_ = 3;
    int get_mode() const override{
      return mode_;
    }

  };
}

//#include "s21_map.tpp"

#endif //CONTAINERS_S21_MAP_H