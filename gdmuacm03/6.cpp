#include <iostream>
#include <string>
using namespace std;
int main() {
  string s;
  cin >> s;

  int boy = 0, girl = 0;
  const string str_boy = "boy", str_girl = "girl";

  for (int i = 0; i < s.length(); ++i) {
    bool is_boy = false, is_girl = false;
    if (s[i] == '.') continue;
    for (int j = 0; j < str_boy.length(); ++j) {
      if (s[i] == str_boy[j]) {
        for (int k = j; k < str_boy.length() && s[i + k - j] == str_boy[k];
             ++k) {
          s[i + k - j] = '.';
        }
        is_boy = true;
      }
    }
    if (is_boy) {
      boy++;
      continue;
    }

    for (int j = 0; j < str_girl.length(); ++j) {
      if (s[i] == str_girl[j]) {
        for (int k = j; k < str_girl.length() && s[i + k - j] == str_girl[k];
             ++k) {
          s[i + k - j] = '.';
        }
        is_girl = true;
      }
    }
    if (is_girl) {
      girl++;
    }
  }
  cout << boy << endl << girl;
}