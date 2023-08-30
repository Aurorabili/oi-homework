#include <iostream>
#include <string>

int main() {
  using namespace std;

  // Get a line of text from the user
  string s;
  getline(cin, s);

  // Print out each character of the string
  for (char c : s) {
    cout << c << ' ';
  }

  return 0;
}