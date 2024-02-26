#ifndef CPP2_S21_CONTAINERS_2_S21_RB_TREES_H
#define CPP2_S21_CONTAINERS_2_S21_RB_TREES_H

#include "../include/s21_rb_trees.h"
#include "../include/s21_vector.h"

namespace s21 {
  template<typename Key, typename T>
  red_black_tree<Key, T>::red_black_tree(std::initializer_list<Key> initList) {
    root = nullptr;
    for (const auto &item: initList) {
      insert_local(item);
    }
  }

  template<typename Key, typename T>
  red_black_tree<Key, T>::red_black_tree(const red_black_tree &other) noexcept {
    root = nullptr;
    add(other.root);
  }

  template<typename Key, typename T>
  red_black_tree<Key, T>::red_black_tree(red_black_tree &&other) noexcept {
    if (this != &other) {
      root = other.root;
      count_element = other.count_element;
      other.root = nullptr;
      other.count_element = 0;
    }
  }

  template<typename Key, typename T>
  red_black_tree<Key, T> &red_black_tree<Key, T>::operator=(
          red_black_tree &&other) noexcept {
    if (this != &other) {
      if (root != nullptr) {
        free(root);
      }
      root = other.root;
      count_element = other.count_element;
      other.root = nullptr;
      other.count_element = 0;
    } else {
      free(root);
      root = nullptr;
      other.count_element = 0;
    }

    return (*this);
  }

  template<typename Key, typename T>
  red_black_tree<Key, T> &red_black_tree<Key, T>::operator=(const red_black_tree &other) {
    if (this != &other) {
      if (root != nullptr) {
        free(root);
        root = nullptr;
      }
      add(root);
      count_element = other.count_element;
    }

    return *this;
  }

  template<typename Key, typename T>
  red_black_tree<Key, T>::~red_black_tree() {
    if (root != nullptr) {
      free(root);
      root = nullptr;
    }
  }

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::iterator &
  red_black_tree<Key, T>::iterator::operator--() {
    if (current_) {
      if (current_->left != nullptr) {
        current_ = tree->max(current_->left);
      } else {
        while (tree->is_left_child(current_)) {
          current_ = current_->parent;
        }
        current_ = current_->parent;
      }
    } else {
      current_ = tree->max(tree->root);
    }
    return (*this);
  };

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::iterator
  red_black_tree<Key, T>::iterator::operator--(int) {
    iterator temp = *this;
    --(*this);
    return temp;
  };

  template<typename Key, typename T>
  Key red_black_tree<Key, T>::iterator::operator*() const {
    if (current_) {
      return current_->key;
    } else {
      throw std::runtime_error("Iterator is not pointer to  a node");
    }
  }

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::iterator &
  red_black_tree<Key, T>::iterator::operator++() {
    if (current_) {
      if (current_->right != nullptr) {
        current_ = tree->min(current_->right);
      } else {
        while (current_->parent && !tree->is_left_child(current_)) {
          current_ = current_->parent;
        }
        current_ = current_->parent;
      }
    }

    return (*this);
  };

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::iterator
  red_black_tree<Key, T>::iterator::operator++(int) {
    iterator temp = *this;
    ++(*this);
    return temp;
  };


  template<typename Key, typename T>
  void red_black_tree<Key, T>::free(Node *&node) {
    if (node != nullptr) {
      free(node->left);
      free(node->right);
      //    std::cout << node->key << std::endl;
      delete node;
      node = nullptr;
    }
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::add(const Node *node) {
    if (node != nullptr) {
      this->insert_local(node->key, node->data);
      add(node->left);
      add(node->right);
    }
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::erase(iterator pos) {
    Node *current = root;
    Node *parent = nullptr;
    bool isFound = true;

    if (pos != this->tree_end() && (root->key != pos.current_->key)) {
      while (isFound &&
             (current->key != pos.current_->key)) {
        parent = current;
        if (pos.current_->key < current->key) {
          current = current->left;
        } else {
          current = current->right;
        }
        if (current == nullptr) {
          isFound = false;
        }
      }
    } else if (pos == this->tree_end()) {
      isFound = false;
    }

    if (isFound) {
      erase_node(current, parent);
    }
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::erase_node(Node *current, Node *parent) {
    Node *node = nullptr;
    Node *child = nullptr;
    if (current->left == nullptr && current->right == nullptr && current->parent != nullptr) {
      node = current;
      if (is_left_child(current)) {
        parent->left = nullptr;
      } else {
        parent->right = nullptr;
      }
    } else if (current->left != nullptr && current->right == nullptr) {
      node = current->left;
      current->key = node->key;
      current->data = node->data;
      current->left = nullptr;
    } else if (current->left == nullptr && current->right != nullptr) {
      node = current->right;
      current->key = node->key;
      current->data = node->data;
      current->right = nullptr;
    } else if (!(current->left == nullptr && current->right == nullptr && current->parent == nullptr)) {
      child = current->left;
      while (child->right) {
        child = child->right;
      }
      current->key = child->key;
      current->data = current->data;
      if (child->key != current->left->key) {
        if (child->left != nullptr) {
          child->parent->right = child->left;
        } else {
          child->parent->right = nullptr;
        }
      } else {
        current->left = nullptr;
      }
      node = child;
    }
    count_element--;
    delete node;
    node = nullptr;
  }

  template<typename Key, typename T>
  typename std::pair<typename red_black_tree<Key, T>::Node *, bool>
  red_black_tree<Key, T>::insert_local(const Key &key, const T &value, int mode) {
    bool result = true;
    Node *new_node = new Node(key, value);
    Node *copy_node = nullptr;
    Node *current = root;
    Node *parent = nullptr;

    while (current != nullptr) {
      parent = current;

      if (key < current->key) {
        current = current->left;
      } else if (key > current->key) {
        current = current->right;
      } else {
        copy_node = current;
        current = current->right;
        new_node->id++;
        result = false;
      }
    }

    new_node->parent = parent;
    if (parent == nullptr) {
      new_node->color = Color::kBLACK;
      root = new_node;
      count_element++;
    } else if ((new_node->key < parent->key) && (result || mode == 2)) {
      parent->left = new_node;
      count_element++;
    } else if ((new_node->key > parent->key && result) || (mode == 2)) {  // add 2 = kMultiset
      parent->right = new_node;
      count_element++;
    } else {
      if (mode == 4) {
        copy_node->data = new_node->data;
        copy_node->pair.second = new_node->data;
      }
      delete new_node;
      new_node = nullptr;
    }

    if (new_node != nullptr && mode != 4) {
      recolor_and_rotate(new_node);
    }
    if (new_node == nullptr && mode == 3) {
      new_node = copy_node;
    }

    return std::pair<Node *, bool>(new_node, result);
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::recolor_and_rotate(Node *node) {
    Node *parent = node->parent;

    if (((node->key != root->key) || (node->key == root->key && node->id != root->id))
        && (parent->color == kRED)) {
      Node *grand = node->parent->parent;
      Node *uncle = (is_left_child(parent)) ? grand->right : grand->left;
      if (uncle && uncle->color == kRED) {
        handle_recoloring(parent, uncle, grand);
      } else if (is_left_child(parent)) {
        handle_left_situations(node, parent, grand);
      } else if (!is_left_child(parent)) {
        handle_right_situations(node, parent, grand);
      }

    }
    root->color = kBLACK;
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::handle_recoloring(Node *parent, Node *uncle, Node *grand) {
    swap_colors(uncle);
    swap_colors(parent);
    swap_colors(grand);
    recolor_and_rotate(grand);
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::handle_left_situations(Node *node, Node *parent, Node *grand) {
    if (!is_left_child(node)) {
      rotate_left(parent);
      node->color = kBLACK;
    }
    swap_colors(parent);
    swap_colors(grand);
    rotate_right(grand);

    recolor_and_rotate(is_left_child(node) ? parent : grand);
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::handle_right_situations(Node *node, Node *parent, Node *grand) {
    if (is_left_child(node)) {
      rotate_right(parent);
      node->color = kBLACK;
    }
    swap_colors(parent);
    swap_colors(grand);
    rotate_left(grand);
    recolor_and_rotate(is_left_child(node) ? grand : parent);
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::rotate_left(Node *node) {
    Node *right_node = node->right;
    node->right = right_node->left;
    if (node->right != nullptr) {
      node->right->parent = node;
    }
    right_node->left = node;
    right_node->parent = node->parent;
    update_children_of_parents(node, right_node);
    node->parent = right_node;
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::rotate_right(Node *node) {
    Node *left_node = node->left;
    node->left = left_node->right;
    if (node->left != nullptr) {
      node->left->parent = node;
    }
    left_node->right = node;
    left_node->parent = node->parent;
    update_children_of_parents(node, left_node);
    node->parent = left_node;
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::update_children_of_parents(Node *node, Node *temp_node) {
    if (node->parent == nullptr) {
      root = temp_node;
    } else if (is_left_child(node)) {
      node->parent->left = temp_node;
    } else {
      node->parent->right = temp_node;
    }
  }

  template<typename Key, typename T>
  void red_black_tree<Key, T>::swap_colors(Node *a) {
    a->color = (a->color == kBLACK) ? kRED : kBLACK;
  }

  template<typename Key, typename T>
  bool red_black_tree<Key, T>::is_left_child(const Node *node) {
    bool result = false;
    if (node->parent && node->parent->left && node->key == node->parent->left->key &&
        node->id == node->parent->left->id) { // TODO node->parent?
      result = true;
    }
    return result;
  }

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::Node *red_black_tree<Key, T>::find_local(
          const Key &value) {
    Node *current = root;
    iterator it;

    if (current) {
      while ((current) &&
             (current->key != value)) {
        if (current->key < value) {
          current = current->right;
        } else {
          current = current->left;
        }
      }
    }
    return current;
  };

  template<typename Key, typename T>
  bool red_black_tree<Key, T>::contains(const Key &value) {
    bool result = false;
    if (this->find_local(value) != nullptr) {
      result = true;
    }
    return result;
  }

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::Node *red_black_tree<Key, T>::min(Node *node) {
    Node *current = node;
    if (current) {
      while (current->left != nullptr) {
        current = current->left;
      }
    }
    return current;
  };

  template<typename Key, typename T>
  typename red_black_tree<Key, T>::Node *red_black_tree<Key, T>::max(Node *node) {
    Node *current = node;
    if (current) {
      while (current->right != nullptr) {
        current = current->right;
      }
    }
    return current;
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::clear() {
    if (root != nullptr) {
      free(root);
      root = nullptr;
      count_element = 0;
    }
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::swap(red_black_tree &other) {
    std::swap(root, other.root);
    std::swap(count_element, other.count_element);
  };

  template<typename Key, typename T>
  void red_black_tree<Key, T>::merge(red_black_tree<Key, T> &other) {
    if (this != &other && other.root != nullptr) {
      iterator it = other.tree_begin();
      s21::vector<std::pair<Key, T>> remainder;  // TODO заменить на свой
      while (it.current_) {
        if (find_local(it.current_->key) != nullptr) {
          remainder.PushBack(std::pair(it.current_->key, it.current_->data));
        }
        insert_local(it.current_->key, it.current_->data);
        it++;
      }

      free(other.root);
      other.root = nullptr;
      other.count_element = 0;
      if (remainder.GetSize()) {
        for (int i = 0; i != (int)remainder.GetSize(); ++i) {
          other.insert_local(remainder[i].first, remainder[i].second);
        }
      }
    }
  };

  template<typename Key, typename T>
  bool red_black_tree<Key, T>::empty() {
    bool result = true;
    if (root) {
      result = false;
    }
    return result;
  }

  template<typename Key, typename T>
  size_t red_black_tree<Key, T>::size() {
    return count_element;
  }

  template<typename Key, typename T>
  size_t red_black_tree<Key, T>::count_elem(const Key &key) {
    auto start = tree_begin();
    size_t count = 0;
    while (start != this->tree_end()) {
      if (start.current_->key == key) {
        count++;
      }
      start++;
    }
    return count;
  }
}  // namespace s21

#endif //CPP2_S21_CONTAINERS_2_S21_RB_TREES_H
