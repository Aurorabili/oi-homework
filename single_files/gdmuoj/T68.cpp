#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Matrix {
 public:
  Matrix(int n, int m) : n_(n), m_(m), data_(n, std::vector<int>(m)) {}

  int& operator()(int i, int j) { return data_[i][j]; }

 private:
  int n_, m_;
  std::vector<std::vector<int>> data_;
};

int main() {
  using namespace std;

  Matrix m(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> m(i, j);
    }
  }

  set<int> principal_elements;
  for (int i = 0; i < 3; ++i) {
    principal_elements.insert(m(i, i));
    principal_elements.insert(m(i, 2 - i));
  }
  int sum = 0;
  for_each(principal_elements.begin(), principal_elements.end(),
           [&sum](int x) { sum += x; });
  cout << sum << endl;
  return 0;
}