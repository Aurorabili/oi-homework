#include <iostream>
#include <string>

int main() {
  using namespace std;

  const string STR = "codeforces";

  int p;
  cin >> p;
  while (p--) {
    string str;
    int k = 0;
    cin >> str;
    for (string::size_type i = 0; i < str.length(); i++) {
      if (str[i] != STR[i]) {
        k++;
      }
    }
    cout << k << endl;
  }
  return 0;
}