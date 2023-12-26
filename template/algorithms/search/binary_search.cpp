#include <array>
#include <iostream>

template <typename T, std::size_t N>
int binary_search(std::array<T, N>& arr, T key) {
  int l = 0, r = N - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == key) return m;
    if (arr[m] < key)
      l = m + 1;
    else
      r = m - 1;
  }
  return -1;
}

int main() {
  std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << binary_search(arr, 6) << '\n';
}