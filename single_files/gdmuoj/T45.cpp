#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  using namespace std;

  vector<string> v;
  for (int i = 0; i < 3; ++i) {
    string s;
    getline(cin, s);
    v.push_back(s);
  }

  sort(v.begin(), v.end(),
       [](string a, string b) { return a.length() < b.length(); });

  for (auto s : v) cout << s << '\n';

  return 0;
}