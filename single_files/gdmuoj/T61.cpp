#include <iostream>

int factorial(int n) { return (n == 0) ? 1 : (n * factorial(n - 1)); }

int main() {
  using namespace std;
  int a, b, c;
  cin >> a >> b >> c;
  cout << a << "! + " << b << "! + " << c << "! = "
       << (a ? factorial(a) : 0) + (b ? factorial(b) : 0) +
              (c ? factorial(c) : 0)
       << endl;
  return 0;
}