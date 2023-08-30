#include <iostream>
int main() {
  using namespace std;
  int a;
  cin >> a;
  cout << ((a % 2 || a == 2) ? "NO" : "YES");
  return 0;
}