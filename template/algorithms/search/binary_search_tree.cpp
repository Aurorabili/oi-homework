#include <iostream>
#include <memory>
#include <queue>

template <class T>
class BinarySearchTree {
 public:
  struct Node;

  typedef Node* node_ptr;

  struct Node {
    T value;
    node_ptr left;
    node_ptr right;
    node_ptr parent;

    Node(const T& value)
        : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
    Node(const T& value, node_ptr left, node_ptr right, node_ptr parent)
        : value(value), left(left), right(right), parent(parent) {}
  };

  BinarySearchTree();
  ~BinarySearchTree();
  explicit BinarySearchTree(std::initializer_list<T> init);

  node_ptr root() { return root_; }
  node_ptr findMax(node_ptr node);
  node_ptr findMin(node_ptr node);
  node_ptr find(const T& key);
  bool isEmpty() { return root_ == nullptr; }
  void insert(const T& key);
  void transplant(node_ptr u, node_ptr v);
  void remove(node_ptr node);

  void preOrder(node_ptr node) {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    preOrder(node->left);
    preOrder(node->right);
  }

  void inOrder(node_ptr node) {
    if (node == nullptr) return;

    std::stack<node_ptr> stack;
    node_ptr current = node;

    while (current != nullptr || !stack.empty()) {
      while (current != nullptr) {
        stack.push(current);
        current = current->left;
      }

      current = stack.top();
      stack.pop();

      std::cout << current->value << " ";

      current = current->right;
    }
  }

  void postOrder(node_ptr node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->value << " ";
  }

 private:
  node_ptr root_;

  BinarySearchTree(BinarySearchTree&);
  BinarySearchTree& operator=(BinarySearchTree&);

 private:
  node_ptr find_(const T& key, node_ptr node);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
  std::queue<node_ptr> q;
  q.push(root_);

  while (!q.empty()) {
    node_ptr node = q.front();
    q.pop();

    if (node->left != nullptr) q.push(node->left);
    if (node->right != nullptr) q.push(node->right);

    delete node;
  }
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> init) {
  for (const T& item : init) {
    insert(item);
  }
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>& bst) {
  if (this != &bst) {
    std::queue<node_ptr> q;
    q.push(root_);

    while (!q.empty()) {
      node_ptr node = q.front();
      q.pop();

      if (node->left != nullptr) q.push(node->left);
      if (node->right != nullptr) q.push(node->right);

      delete node;
    }

    root_ = bst.root_;
    bst.root_ = nullptr;
  }

  return *this;
}

template <class T>
BinarySearchTree<T>::node_ptr BinarySearchTree<T>::findMax(
    BinarySearchTree<T>::node_ptr node) {
  if (node->right == nullptr) return node;
  return findMax(node->right);
}

template <class T>
BinarySearchTree<T>::node_ptr BinarySearchTree<T>::findMin(
    BinarySearchTree<T>::node_ptr node) {
  if (node->left == nullptr) return node;
  return findMin(node->left);
}

template <class T>
BinarySearchTree<T>::node_ptr BinarySearchTree<T>::find(const T& key) {
  return find_(key, root_);
}

template <class T>
BinarySearchTree<T>::node_ptr BinarySearchTree<T>::find_(
    const T& key, typename BinarySearchTree<T>::node_ptr node) {
  if (node == nullptr || node->value == key)
    return node;
  else
    return find_(key, node->value < key ? node->right : node->left);
}

template <class T>
void BinarySearchTree<T>::insert(const T& data) {
  node_ptr new_node(new Node(data));

  if (!root_) {
    root_ = new_node;
    return;
  }

  Node* x = root_;
  Node* parent = nullptr;

  while (x != nullptr) {
    parent = x;
    x = (data < x->value) ? x->left : x->right;
  }

  new_node->parent = parent;

  if (parent->value < data)
    parent->right = new_node;
  else
    parent->left = new_node;
}

template <class T>
void BinarySearchTree<T>::transplant(BinarySearchTree<T>::node_ptr u,
                                     BinarySearchTree<T>::node_ptr v) {
  if (u->parent == nullptr)
    root_ = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;

  if (v != nullptr) v->parent = u->parent;
}

template <class T>
void BinarySearchTree<T>::remove(BinarySearchTree<T>::node_ptr node) {
  if (node->left == nullptr)
    transplant(node, node->right);
  else if (node->right == nullptr)
    transplant(node, node->left);
  else {
    auto y = findMin(node->right);
    if (y->parent != node) {
      transplant(y, y->right);
      y->right = node->right;
      y->right->parent = y;
    }
    transplant(node, y);
    y->left = node->left;
    y->left->parent = y;
  }

  delete node;
}

int main() {
  BinarySearchTree<int> bst{5, 3, 7, 2, 4, 6, 8, 1, 9};

  auto node = bst.find(5);
  std::cout << node->value << std::endl;

  bst.remove(node);

  if (bst.root() != nullptr) std::cout << bst.root()->value << std::endl;

  std::cout << bst.findMax(bst.root())->value << ' '
            << bst.findMin(bst.root())->value << std::endl;

  return 0;
}