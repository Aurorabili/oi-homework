#include <iostream>

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  using namespace std;

  int n, m;
  cin >> n >> m;

  if (n < 0 || m < 0) {
    cout << "Invalid input!";
    return 0;
  }

  int gcd_result = gcd(n, m);
  int lcm_result = n * m / gcd_result;
  cout << gcd_result << endl << lcm_result << endl;
  return 0;
}