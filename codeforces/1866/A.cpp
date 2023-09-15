#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int min_step = 0x3f3f3f3f;
  while (n--) {
    int a;
    cin >> a;
    min_step = min(min_step, abs(a));
  }
  cout << min_step << endl;
}