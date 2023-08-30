#include <iomanip>
#include <iostream>

int main() {
  using namespace std;

  double a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(3) << max(max(a, b), c) << setprecision(2)
       << '\n'
       << max(max(a, b), c);
  return 0;
}