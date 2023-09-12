#include <iostream>

using namespace std;

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a[100010] = {0}, b[100010] = {0};
    cin >> n;
    a[1] = 1;
    b[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (a[i - 1] * 2 <= n) {
        a[i] = a[i - 1] * 2;
        ++b[a[i]];
      } else {
        for (int j = 1; j <= i; ++j) {
          if (b[j] == 0) {
            a[i] = j;
            ++b[a[i]];
            break;
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
}