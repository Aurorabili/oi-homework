#include <iostream>
#include <queue>
#include <vector>

const int INF = 0x3f3f3f3f;

class Matrix {
 public:
  Matrix(int n, int m) : n_(n), m_(m), data_(n, std::vector<int>(m)) {}

  int& operator()(int i, int j) { return data_[i][j]; }

  std::pair<int, int> saddle_point() {
    std::vector<int> row_max(n_, -INF);
    std::vector<int> col_min(m_, INF);
    for (int i = 0; i < n_; ++i) {
      for (int j = 0; j < m_; ++j) {
        row_max[i] = std::max(row_max[i], data_[i][j]);
        col_min[j] = std::min(col_min[j], data_[i][j]);
      }
    }
    for (int i = 0; i < n_; ++i) {
      for (int j = 0; j < m_; ++j) {
        if (data_[i][j] == row_max[i] && data_[i][j] == col_min[j]) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }

 private:
  int n_, m_;
  std::vector<std::vector<int>> data_;
};

int main() {
  using namespace std;

  int n, m;
  cin >> n >> m;
  Matrix matrix(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix(i, j);
    }
  }

  auto saddle_point = matrix.saddle_point();
  if (saddle_point.first == -1) {
    cout << "NO" << endl;
  } else {
    cout << saddle_point.first + 1 << " " << saddle_point.second + 1 << endl;
  }
  return 0;
}