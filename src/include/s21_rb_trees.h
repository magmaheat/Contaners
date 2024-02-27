#ifndef CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_RB_TREES_H_
#define CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_RB_TREES_H_

#include <algorithm>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename Key, typename T>
class red_black_tree {
 public:
  red_black_tree() : root(nullptr) {}
  red_black_tree(std::initializer_list<Key> initList);
  red_black_tree(const red_black_tree& other) noexcept;
  red_black_tree(red_black_tree&& other) noexcept;
  ~red_black_tree();
  red_black_tree& operator=(red_black_tree&& other) noexcept;
  red_black_tree& operator=(const red_black_tree& other);

  typedef struct Node {
    Key key;
    T data;
    std::pair<const Key, T> pair;
    Node* parent;
    Node* left;
    Node* right;
    int color;
    int id;
    Node()
        : key(),
          data(),
          pair(),
          parent(nullptr),
          left(nullptr),
          right(nullptr),
          color(kRED),
          id(1) {}
    Node(const Key& k, const T& v)
        : key(k),
          data(v),
          pair(k, v),
          parent(nullptr),
          left(nullptr),
          right(nullptr),
          color(Color::kRED),
          id(1) {}
    Node(const Node& other)
        : key(other.key),
          data(other.data),
          pair(other.pair),
          parent(other.parent),
          left(other.left),
          right(other.right),
          color(other.color),
          id(other.id) {}
    Node(Node&& other) noexcept
        : key(std::move(other.key)),
          data(std::move(other.data)),
          pair(std::move(other.pair)),
          parent(std::move(other.parent)),
          left(std::move(other.left)),
          right(std::move(other.right)),
          color(std::move(other.color)),
          id(std::move(other.id)) {
      other.parent = nullptr;
      other.left = nullptr;
      other.right = nullptr;
    }

    ~Node() = default;
  } Node;

  enum Color { kRED, kBLACK };

  class tree_iterator {
    friend class red_black_tree;

   public:
    tree_iterator() : current(nullptr), tree(nullptr) {}

    explicit tree_iterator(Node* node, red_black_tree<Key, T>* tree_ref)
        : current(node), tree(tree_ref) {}

    Key operator*() const;

    virtual tree_iterator& operator--();
    virtual tree_iterator& operator++();
    virtual tree_iterator operator--(int);
    virtual tree_iterator operator++(int);
    virtual bool operator==(const tree_iterator& other) const {
      bool result;
      if (!current && !other.current) {
        result = true;
      } else if (!current || !other.current) {
        result = false;
      } else {
        result = current->key == other.current->key;
      }

      return result;
    }

    virtual bool operator!=(const tree_iterator& other) const {
      bool result;
      if (!current && !other.current) {
        result = false;
      } else if (!current || !other.current) {
        result = true;
      } else {
        result = current->key != other.current->key;
      }

      return result;
    }

   protected:
    Node* current;
    red_black_tree<Key, T>* tree;
  };

  using iterator = tree_iterator;

  void erase(iterator pos);
  bool contains(const Key& value);
  void clear();
  void swap(red_black_tree& other);
  void merge(red_black_tree& other);
  bool empty();
  size_t size();
  size_t max_size() {
    return std::numeric_limits<size_t>::max() / 2 / sizeof(Node);
  }

 protected:
  Node* root;
  size_t count_element = 0;
  iterator tree_begin() { return iterator(min(root), this); }
  iterator tree_end() { return iterator(nullptr, this); }
  size_t count_elem(const Key& key);
  std::pair<Node*, bool> insert_local(const Key& key, const T& value = T(),
                                      int mode = 0);
  Node* find_local(const Key& value);
  Node* min(Node* node);
  Node* max(Node* node);
  void add(const Node* node);
  void free(Node*& node);

 private:
  void erase_node(Node* current, Node* parent);
  void recolor_and_rotate(Node* node);
  void swap_colors(Node* a);
  bool is_left_child(const Node* node);
  void handle_recoloring(Node* parent, Node* uncle, Node* grand);
  void handle_left_situations(Node* node, Node* parent, Node* grand);
  void handle_right_situations(Node* node, Node* parent, Node* grand);
  void rotate_left(Node* node);
  void rotate_right(Node* node);
  void update_children_of_parents(Node* node, Node* temp_node);
};
}  // namespace s21

#include "../functions/s21_rb_trees.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_INCLUDE_S21_RB_TREES_H_