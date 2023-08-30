#include <iostream>

int main() {
  using namespace std;

  int n = 10;
  // cin >> n;
  int a[101][101] = {{0}};
  a[1][1] = 1;
  a[2][1] = 1;
  a[2][2] = 1;

  for (int i = 3; i <= n; i++) {
    a[i][1] = 1;
    a[i][i] = 1;
    for (int j = 2; j <= i - 1; j++) {
      a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}