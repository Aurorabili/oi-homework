#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  cout << s.length() << endl;

  for (unsigned int i = 0; i < s.length(); ++i) {
    if (i != s.length() - 1)
      cout << s[i] << " ";
    else
      cout << s[i];
  }
  cout << endl;

  reverse(s.begin(), s.end());

  for (auto i : s) {
    cout << i;
  }

  return 0;
}