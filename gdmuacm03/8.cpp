#include <iostream>

long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

auto gcd = [](auto &&self, int a, int b) -> int {
  return b == 0 ? a : self(self, b, a % b);
};

auto lcm = [](int a, int b) -> int { return a * b / gcd(gcd, a, b); };

int main() {
  int n;
  std::cin >> n;

  long long totalCases = factorial(n - 1);

  std::cout << totalCases;

  return 0;
}
