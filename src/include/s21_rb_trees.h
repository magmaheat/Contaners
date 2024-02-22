#ifndef CPP2_S21_CONTAINERS_1_S21_RED_BLACK_FORESTS_H_
#define CPP2_S21_CONTAINERS_1_S21_RED_BLACK_FORESTS_H_

#include <initializer_list>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 230584300921369395

// TODO оптимизировать ptr++ and ptr--
// TODO подстроить find под map
// TODO подстроить insert под map

namespace s21 {
  template<typename Key, typename T>
  class red_black_tree {
  public:
    // TODO обновить нейминг
    using key_type = Key;
    using value_type = T;
    using reference = key_type&;
    using const_reference = const key_type&;
    using size_type = size_t;

    red_black_tree() : root_(nullptr) {}
    red_black_tree(std::initializer_list<Key> initList);
    red_black_tree(const red_black_tree &other) noexcept;
    red_black_tree(red_black_tree &&other) noexcept;
    ~red_black_tree();
    red_black_tree &operator=(red_black_tree &&other) noexcept;
    red_black_tree &operator=(const red_black_tree &other);

    typedef struct Node {
      Key key;
      T data;
      std::pair<const Key, T> pair;
      Node *parent;
      Node *left;
      Node *right;
      int color;
      Node() : key(), data(), pair(), parent(nullptr), left(nullptr), right(nullptr), color(kRED) {}
      Node(const Key& k, const T& v) : key(k), data(v), pair(k, v), parent(nullptr), left(nullptr), right(nullptr), color(Color::kRED) {}
    } Node; // TODO add constructor


    enum Color {
      kRED,
      kBLACK
    };

    class tree_iterator {
    friend class red_black_tree;
      public:
        tree_iterator() : current_(nullptr), tree(nullptr) {}

      explicit tree_iterator(Node *node, red_black_tree<Key, T>* tree_ref) : current_(node), tree(tree_ref) {
        }

      Key operator*() const;

      virtual tree_iterator &operator--();
      virtual tree_iterator &operator++();
      virtual tree_iterator operator--(int);
      virtual tree_iterator operator++(int);
      virtual bool operator==(const tree_iterator &other) const {
        bool result;
        if (!current_ && !other.current_) {
          result = true;
        } else if (!current_ || !other.current_) {
          result = false;
        } else {
          result = current_->key == other.current_->key;
        }

        return result;
      }
      virtual bool operator!=(const tree_iterator &other) const {
        bool result;
        if (!current_ && !other.current_) {
          result = false;
        } else if (!current_ || !other.current_) {
          result = true;
        } else {
          result = current_->key != other.current_->key;
        }

        return result;
      }
    protected:
      Node* current_;
      red_black_tree<Key, T>* tree;

    private:
    };

    using iterator = tree_iterator;

    void erase(iterator pos);
    bool contains(const Key &value);
    void clear();
    void swap(red_black_tree &other);
    void merge(red_black_tree &other);
    bool empty();
    size_t size();
    size_t max_size() { return MAX_SIZE; }
    void display();


  protected:
    Node* root_;
    iterator tree_begin() { return iterator (min(), this); }
    iterator tree_end() { return iterator(nullptr, this); }
    size_t count_elem(iterator pos);
    std::pair<Node*, bool> insert_local(const Key& key, const T& value =  T());
    Node* find_local(const Key &value);
    virtual int get_mode() const {
      return 0;
    }
    Node *min();
    Node *max();
    void add(const Node *node);
    void free(Node *&node);

  private:
    void print_tree(Node* node, int indent =  0);
    void recolor_and_rotate(Node *node);
    void swap_colors(Node *a);
    bool is_left_child(const Node *node);
    void handle_recoloring(Node *parent, Node *uncle, Node *grand);
    void handle_left_situations(Node *node, Node *parent, Node *grand);
    void handle_right_situations(Node *node, Node *parent, Node *grand);
    void rotate_left(Node *node);
    void rotate_right(Node *node);
    void update_children_of_parents(Node *node, Node *temp_node);
    size_t max_size_ = 230584300921369395;
  };
}  // namespace s21

#include "../functions/s21_rb_trees_tpp.h"  // TODO transform to .tpp

#endif  // CPP2_S21_CONTAINERS_1_S21_RED_BLACK_FORESTS_H_
