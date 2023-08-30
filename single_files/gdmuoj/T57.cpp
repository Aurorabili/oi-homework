#include <iostream>

bool is_prime(int n) {
  if (n == 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int* goldbach(int n) {
  int* result = new int[2];
  for (int i = 2; i <= n / 2; i++) {
    if (is_prime(i) && is_prime(n - i)) {
      result[0] = i;
      result[1] = n - i;
      return result;
    }
  }
  return result;
}

int main() {
  using namespace std;
  int n;
  cin >> n;
  int* result = goldbach(n);
  cout << n << "=" << result[0] << "+" << result[1] << endl;
  delete[] result;
  return 0;
}