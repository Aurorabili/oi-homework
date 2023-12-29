#include <iostream>
#include <memory>

struct node;
using node_ptr = std::unique_ptr<node>;
struct node {
  int weight;
  node_ptr left;
  node_ptr right;
};

int dfs(const node *node, int depth) {
  if (!node->left && !node->right)
    return node->weight * depth;

  int sum = 0;
  if (node->left)
    sum += dfs(node->left.get(), depth + 1);
  if (node->right)
    sum += dfs(node->right.get(), depth + 1);
  return sum;
}

int main() {
  int n;
  std::cin >> n;

  int weight[10];
  for (int i = 0; i < n; ++i) {
    std::cin >> weight[i];
  }

  node_ptr root_ = std::make_unique<node>();
  root_->weight = weight[0];

  for (int i = 0; i < n - 1; ++i) {
    int parent, child;
    std::cin >> parent >> child;
    if (parent == 0) {
      root_->left = std::make_unique<node>();
      root_->left->weight = weight[child];
    } else {
      node *parent_ = root_.get();
      for (int j = 1; j < parent; ++j) {
        parent_ = parent_->left.get();
      }
      if (!parent_->left) {
        parent_->left = std::make_unique<node>();
        parent_->left->weight = weight[child];
      } else {
        parent_->right = std::make_unique<node>();
        parent_->right->weight = weight[child];
      }
    }
  }

  std::cout << dfs(root_.get(), 0) << '\n';
  return 0;
}