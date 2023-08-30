#include <iostream>

int main() {
  using namespace std;

  int p, count = 0;
  cin >> p;
  while (p--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c >= 2) {
      count++;
    }
  }
  cout << count;
  return 0;
}