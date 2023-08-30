#include <iostream>
#include <vector>

using namespace std;

int main() {
  int p;
  cin >> p;
  while (p--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int min_odd = 0x3f3f3f3f, min_even = 0x3f3f3f3f;
    for (auto x : a) {
      if (x % 2 == 0)
        min_even = min(min_even, x);
      else
        min_odd = min(min_odd, x);
    }
    if ((min_even - min_odd >= 0) || (min_odd == 0x3f3f3f3f) ||
        (min_even == 0x3f3f3f3f)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}