#include <iostream>
#include <type_traits>

int main() {
  using namespace std;
  int a[10010] = {0}, n = 10;
  // cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n - 1; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  return 0;
}