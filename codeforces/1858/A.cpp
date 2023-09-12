#include <iostream>

using namespace std;

int main() {
  int p;
  cin >> p;
  while (p--) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b + c) {
      cout << "First" << endl;
      continue;
    }

    if (c % 2 != 0) {
      if (a >= b) {
        cout << "First" << endl;
      } else {
        cout << "Second" << endl;
      }
    } else {
      if (b >= a) {
        cout << "Second" << endl;
      } else {
        cout << "First" << endl;
      }
    }
  }
}