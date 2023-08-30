#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
  using namespace std;

  double a, b, c;
  cin >> a >> b >> c;
  double p = (a + b + c) / 2.0;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  cout << fixed << setprecision(3) << s;
  return 0;
}