#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>

int main() {
  using namespace std;

  string s;
  getline(cin, s);

  for (char c : s) {
    if (isalpha(c)) {
      if (isalpha(c + 1))
        cout << char(c + 1);
      else
        cout << char(c + 1 - 26);
    } else
      cout << c;
  }

  return 0;
}