#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using namespace std;

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int p;
  cin >> p;
  while (p--) {
    int tmp = *(a.end() - 1);
    a.insert(a.begin(), tmp);
    a.pop_back();
  }
  for_each(a.begin(), a.end(), [](const int &n) { cout << n << " "; });

  return 0;
}