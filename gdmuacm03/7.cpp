#include <iostream>
#define MAXN 1000010
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a[MAXN] = {0};
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    a[t]++;
  }
  for (int i = 0; i < MAXN; ++i) {
    if (a[i]) {
      k--;
      if (k == 0) {
        cout << i;
        return 0;
      }
    }
  }
  cout << "NO RESULT";
  return 0;
}