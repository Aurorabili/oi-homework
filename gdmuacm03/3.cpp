#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int level = 0;
  int exp = 0;
  double health = 10;

  for (int i = 0; i < n; i++) {
    double x, a;
    cin >> x >> a;

    // the max health is 10
    if (health - x > 10) {
      health = 10;
    } else {
      health -= x;
    }

    if (health <= 0) {
      break;
    }
    exp += a;
  }

  while (exp >= pow(2, level)) {
    exp -= pow(2, level);
    level++;
  }

  cout << level << " " << exp << endl;

  return 0;
}