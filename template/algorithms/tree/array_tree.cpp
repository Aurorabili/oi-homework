#include <iostream>
#include <queue>
#include <vector>

class ArrayTree {
 private:
  std::vector<int> tree;

 public:
  ArrayTree(int size) { tree.resize(size + 1); }
  ~ArrayTree() { tree.clear(); }
  explicit ArrayTree(std::initializer_list<int> list) {
    for (auto& i : list) {
      tree.push_back(i);
    }
  }

  int get(int index) { return tree[index]; }
  int parent(int index) { return index / 2; }
  int left(int index) { return index * 2 + 1; }
  int right(int index) { return index * 2 + 2; }

  void update(int index, int value) { tree[index] = value; }
  void preOrder(int index) {
    if (index >= tree.size()) return;
    std::cout << tree[index] << " ";
    preOrder(left(index));
    preOrder(right(index));
  }
  void inOrder(int index) {
    if (index >= tree.size()) return;
    inOrder(left(index));
    std::cout << tree[index] << " ";
    inOrder(right(index));
  }
  void postOrder(int index) {
    if (index >= tree.size()) return;
    postOrder(left(index));
    postOrder(right(index));
    std::cout << tree[index] << " ";
  }

  std::vector<int>& getTree() { return tree; }
};

int main() {
  ArrayTree tree{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << "PreOrder: ";
  tree.preOrder(0);
  std::cout << std::endl;

  return 0;
}