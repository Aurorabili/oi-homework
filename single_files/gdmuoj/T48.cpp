#include <algorithm>
#include <iostream>
#include <list>

int josephus_math_solve(int n, int k) {
  if (n == 1) {
    return 1;
  }
  return (josephus_math_solve(n - 1, k) + k - 1) % n + 1;
}

int josephus_list_solve(int n, int k) {
  using namespace std;

  list<int> list_numbers;
  for (int i = 1; i <= n; i++) {
    list_numbers.push_back(i);
  }

  auto it = list_numbers.begin();
  while (list_numbers.size() > 1) {
    for (int i = 0; i < k - 1; i++) {
      it++;
      if (it == list_numbers.end()) {
        it = list_numbers.begin();
      }
    }
    it = list_numbers.erase(it);
    if (it == list_numbers.end()) {
      it = list_numbers.begin();
    }
  }
  return list_numbers.front();
}

int main() {
  using namespace std;

  int n, k = 3;
  cin >> n;
  cout << josephus_list_solve(n, k) << endl;
  return 0;
}