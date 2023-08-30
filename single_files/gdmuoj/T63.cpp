#include <iostream>

double legendre(int n, double x) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x;
  } else {
    return ((2 * n - 1) * x * legendre(n - 1, x) -
            (n - 1) * legendre(n - 2, x)) /
           n;
  }
}

int main() {
  using namespace std;
  int n;
  double x;
  cin >> n >> x;
  cout << legendre(n, x);
  return 0;
}