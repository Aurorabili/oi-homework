#include <algorithm>
#include <iostream>
#include <string>

int main() {
  using namespace std;

  int n, m;
  string str;
  cin >> n >> str >> m;
  for_each(str.begin() + m - 1, str.end(), [](char &c) { cout << c; });

  return 0;
}