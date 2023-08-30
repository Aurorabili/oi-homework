#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using namespace std;

  vector<int> v;
  for (int i = 0; i < 10; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  iter_swap(v.begin(), min_element(v.begin(), v.end()));
  iter_swap(v.end() - 1, max_element(v.begin(), v.end()));

  std::for_each(v.begin(), v.end(),
                [](const int &n) { std::cout << n << " "; });
  return 0;
}