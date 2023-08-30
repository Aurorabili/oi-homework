#include <algorithm>
#include <iostream>
#include <vector>

// Matrix Class with transpose method
class Matrix {
 public:
  Matrix(int n, int m) : n(n), m(m) { data.resize(n * m); }
  int& operator()(int i, int j) { return data[i * m + j]; }
  int operator()(int i, int j) const { return data[i * m + j]; }
  Matrix transpose() const {
    Matrix result(m, n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        result(j, i) = (*this)(i, j);
      }
    }
    return result;
  }

 private:
  int n, m;
  std::vector<int> data;
};

int main() {
  Matrix m(3, 3);

  // Input m
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cin >> m(i, j);
    }
  }

  // Transpose m
  Matrix m_t = m.transpose();

  // Output m_t
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      std::cout << m_t(i, j) << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}