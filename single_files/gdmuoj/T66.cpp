#include <iostream>

int main() {
  using namespace std;

  int n = 100;
  // cin >> n;
  int a[10010] = {0};  // 0 is prime
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] == 0) {
      for (int j = 2; i * j <= n; j++) {
        a[i * j] = 1;
      }
    }
  }

  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] == 0) {
      cout << i;
      if (++count % 10 == 0)
        cout << endl;
      else
        cout << " ";
    }
  }

  return 0;
}