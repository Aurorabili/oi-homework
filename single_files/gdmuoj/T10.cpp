#include <iostream>

int main() {
  using namespace std;

  int profit, price = 0;
  cin >> profit;

  switch (profit / 100000) {
    case 0:
      price = profit * 0.1;
      break;
    case 1:
      price = 10000 + (profit - 100000) * 0.075;
      break;
    case 2:
    case 3:
      price = 10000 + 7500 + (profit - 200000) * 0.05;
      break;
    case 4:
    case 5:
      price = 10000 + 7500 + 10000 + (profit - 400000) * 0.03;
      break;
    case 6:
    case 7:
    case 8:
    case 9:
      price = 10000 + 7500 + 10000 + 6000 + (profit - 600000) * 0.015;
      break;
    default:
      price = 10000 + 7500 + 10000 + 6000 + 6000 + (profit - 1000000) * 0.01;
      break;
  }

  cout << price << endl;
  return 0;
}