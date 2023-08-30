#include <iostream>
#include <string>

int main() {
  using namespace std;

  int p;
  cin >> p;

  while (p--) {
    string str;
    cin >> str;
    cout << ((str.length() > 10)
                 ? str[0] + to_string(str.length() - 2) + str[str.length() - 1]
                 : str)
         << endl;
  }

  return 0;
}