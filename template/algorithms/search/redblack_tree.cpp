#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>

template <class T>
class RedBlackTree {
 public:
  struct Node;
  typedef Node* node_ptr;

  enum Color { RED, BLACK };

  struct Node {
    T data;
    node_ptr left;
    node_ptr right;
    node_ptr parent;

    Color color;

    Node(const T& data)
        : data(data),
          left(nullptr),
          right(nullptr),
          parent(nullptr),
          color(Color::RED) {}
    Node(const T& data, node_ptr left, node_ptr right, node_ptr parent,
         Color color)
        : data(data), left(left), right(right), parent(parent), color(color) {}
  };

  RedBlackTree();
  ~RedBlackTree();
  explicit RedBlackTree(std::initializer_list<T> init);

  node_ptr findMax(node_ptr node);
  node_ptr findMin(node_ptr node);
  node_ptr findMax() { return findMax(root_); }
  node_ptr findMin() { return findMin(root_); }
  node_ptr find(const T& data);
  void insert(const T& data);
  void remove(const T& data);

 private:
  node_ptr root_;
  const node_ptr nil_ = new Node(T(), nullptr, nullptr, nullptr, Color::BLACK);

  void transplant(node_ptr u, node_ptr v);
  void left_rotate(node_ptr node);
  void right_rotate(node_ptr node);
  void insert_fixup(node_ptr node);
  void remove_fixup(node_ptr node);
};

template <class T>
RedBlackTree<T>::RedBlackTree(std::initializer_list<T> init) {
  for (auto& data : init) insert(data);
}

template <class T>
RedBlackTree<T>::RedBlackTree() : root_(nullptr) {}

template <class T>
RedBlackTree<T>::~RedBlackTree() {
  std::queue<node_ptr> q;
  q.push(root_);

  while (!q.empty()) {
    node_ptr node = q.front();
    q.pop();

    if (node->left != nil_) q.push(node->left);
    if (node->right != nil_) q.push(node->right);

    delete node;
  }
  delete nil_;
}

template <class T>
void RedBlackTree<T>::left_rotate(node_ptr node) {
  if (node == nil_ || node->right == nil_) return;

  node_ptr right_child = node->right;

  node->right = right_child->left;
  if (right_child->left != nil_) right_child->left->parent = node;

  right_child->parent = node->parent;
  if (node->parent == nil_)
    root_ = right_child;
  else if (node == node->parent->left)
    node->parent->left = right_child;
  else
    node->parent->right = right_child;

  right_child->left = node;
  node->parent = right_child;
}

template <class T>
void RedBlackTree<T>::right_rotate(node_ptr node) {
  if (node == nil_ || node->left == nil_) return;

  node_ptr left_child = node->left;

  node->left = left_child->right;
  if (left_child->right != nil_) left_child->right->parent = node;

  left_child->parent = node->parent;
  if (node->parent == nil_)
    root_ = left_child;
  else if (node == node->parent->left)
    node->parent->left = left_child;
  else
    node->parent->right = left_child;

  left_child->right = node;
  node->parent = left_child;
}

template <class T>
void RedBlackTree<T>::insert(const T& data) {
  node_ptr new_node(new Node(data, nil_, nil_, nil_, Color::RED));
  if (!root_) {
    new_node->color = Color::BLACK;
    root_ = new_node;
    return;
  }

  node_ptr node = root_;
  node_ptr p = nil_;

  while (node != nil_) {
    p = node;
    node = (node->data > data) ? node->left : node->right;
  }

  new_node->parent = p;
  if (p->data > data)
    p->left = new_node;
  else
    p->right = new_node;

  insert_fixup(new_node);
}

template <class T>
void RedBlackTree<T>::insert_fixup(node_ptr node) {
  while (node->parent->color == Color::RED) {
    // left case
    if (node->parent == node->parent->parent->left) {
      node_ptr uncle = node->parent->parent->right;

      // case 1
      if (uncle->color == Color::RED) {
        node->parent->color = Color::BLACK;
        uncle->color = Color::BLACK;
        node->parent->parent->color = Color::RED;
        node = node->parent->parent;
      } else {  // case 2
        if (node == node->parent->right) {
          node = node->parent;
          left_rotate(node);
        }

        // case 3
        node->parent->color = Color::BLACK;
        node->parent->parent->color = Color::RED;
        right_rotate(node->parent->parent);
      }
    } else {
      node_ptr uncle = node->parent->parent->left;

      if (uncle->color == Color::RED) {
        node->parent->color = Color::BLACK;
        uncle->color = Color::BLACK;
        node->parent->parent->color = Color::RED;
        node = node->parent->parent;
      } else {
        if (node == node->parent->left) {
          node = node->parent;
          right_rotate(node);
        }
        node->parent->color = Color::BLACK;
        node->parent->parent->color = Color::RED;
        left_rotate(node->parent->parent);
      }
    }
  }
  root_->color = Color::BLACK;
}

template <class T>
RedBlackTree<T>::node_ptr RedBlackTree<T>::find(const T& data) {
  node_ptr node = root_;
  while (node != nil_) {
    if (node->data == data)
      return node;
    else if (node->data > data)
      node = node->left;
    else
      node = node->right;
  }
  return nullptr;
}

template <class T>
RedBlackTree<T>::node_ptr RedBlackTree<T>::findMax(node_ptr node) {
  if (node->right == nil_ || node == nil_) return node;
  return findMax(node->right);
}

template <class T>
RedBlackTree<T>::node_ptr RedBlackTree<T>::findMin(node_ptr node) {
  if (node->left == nil_ || node == nil_) return node;
  return findMin(node->left);
}

template <class T>
void RedBlackTree<T>::transplant(node_ptr u, node_ptr v) {
  if (u->parent == nil_)
    root_ = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;

  v->parent = u->parent;
}

template <class T>
void RedBlackTree<T>::remove_fixup(node_ptr node) {
  while (node != root_ && node->color == Color::BLACK) {
    if (node == node->parent->left) {
      node_ptr w = node->parent->right;
      if (w->color == Color::RED) {
        w->color = Color::BLACK;
        node->parent->color = Color::RED;
        left_rotate(node->parent);
        w = node->parent->right;
      }

      if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
        w->color = Color::RED;
        node = node->parent;
      } else {
        if (w->right->color == Color::BLACK) {
          w->left->color = Color::BLACK;
          w->color = Color::RED;
          right_rotate(w);
          w = node->parent->right;
        }

        w->color = node->parent->color;
        node->parent->color = Color::BLACK;
        w->right->color = Color::BLACK;
        left_rotate(node->parent);
        node = root_;
      }
    } else {
      node_ptr w = node->parent->left;
      if (w->color == Color::RED) {
        w->color = Color::BLACK;
        node->parent->color = Color::RED;
        right_rotate(node->parent);
        w = node->parent->left;
      }

      if (w->right->color == Color::BLACK && w->left->color == Color::BLACK) {
        w->color = Color::RED;
        node = node->parent;
      } else {
        if (w->left->color == Color::BLACK) {
          w->right->color = Color::BLACK;
          w->color = Color::RED;
          left_rotate(w);
          w = node->parent->left;
        }

        w->color = node->parent->color;
        node->parent->color = Color::BLACK;
        w->left->color = Color::BLACK;
        right_rotate(node->parent);
        node = root_;
      }
    }
  }
  node->color = Color::BLACK;
}

template <class T>
void RedBlackTree<T>::remove(const T& data) {
  node_ptr node = find(data);
  if (node == nullptr) return;

  node_ptr y = node;
  Color y_original_color = y->color;
  node_ptr x;

  if (node->left == nil_) {
    x = node->right;
    transplant(node, node->right);
  } else if (node->right == nil_) {
    x = node->left;
    transplant(node, node->left);
  } else {
    y = findMin(node->right);
    y_original_color = y->color;
    x = y->right;

    if (y->parent == node)
      x->parent = y;
    else {
      transplant(y, y->right);
      y->right = node->right;
      y->right->parent = y;
    }

    transplant(node, y);
    y->left = node->left;
    y->left->parent = y;
    y->color = node->color;
  }

  if (y_original_color == Color::BLACK) remove_fixup(x);
}

int main() {
  RedBlackTree<int> rbt{3, 7, 5, 2, 4, 6, 8, 1, 9};

  std::cout << rbt.findMax()->data << ' ' << rbt.findMin()->data << std::endl;

  rbt.remove(rbt.findMax()->data);

  std::cout << rbt.findMax()->data << ' ' << rbt.findMin()->data << std::endl;
}
