#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int p;
  cin >> p;
  while (p--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    vector<int> b(n), ans(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }

    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
      ans[a[i].second] = b[i];
    }

    for (auto x : ans) {
      cout << x << " ";
    }
  }
  return 0;
}