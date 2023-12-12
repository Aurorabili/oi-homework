#include <iostream>
using namespace std;

int main() {
  int n, r = 0, r_l = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    r_l = r_l + a + b - 8;
    r += r_l;
  }
  cout << r;
}