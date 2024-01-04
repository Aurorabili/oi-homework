#include <iostream>

template <typename T, std::size_t N> class Stack {
private:
  int stack[N] = {0};
  int top_ = 0, nil_ = 0;

public:
  void push(int x) {
    int index = top_ + 1 % N;
    if (index == nil_ && top_ != nil_) {
      std::cout << "stack overflow" << std::endl;
      return;
    }
    stack[index] = x;
    top_ = index;
  }

  void pop() {
    if (top_ == nil_) {
      std::cout << "stack underflow" << std::endl;
      return;
    }
    top_ = top_ - 1 % N;
  }

  int top() {
    if (top_ == nil_) {
      std::cout << "stack underflow" << std::endl;
      return -1;
    }
    return stack[top_];
  }

  int size() { return top_ - nil_; }
  int get(int index) {
    index = (top_ - index) % N;
    return stack[index];
  }

  bool empty() { return top_ == nil_; }

  Stack() {}
  Stack(std::initializer_list<T> list) {
    for (auto &x : list) {
      push(x);
    }
  }
};

int main() {
  Stack<int, 10> stack = {1, 2, 3, 4, 5};
  std::cout << stack.top() << std::endl;
  stack.pop();
  std::cout << stack.top() << std::endl;
  return 0;
}