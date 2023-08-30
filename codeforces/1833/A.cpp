#include <iostream>
#include <set>
#include <string>

int main() {
  using namespace std;

  int p;
  cin >> p;

  while (p--) {
    int n;
    cin >> n;
    string str;
    cin >> str;

    set<string> melodies;
    for (string::size_type i = 0; i < str.size() - 1; ++i) {
      melodies.insert(str.substr(i, 2));
    }

    cout << melodies.size() << endl;
  }

  return 0;
}