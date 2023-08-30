#include <iostream>
#include <string>

int main() {
  using namespace std;

  string str;         // Create a string to store the input
  getline(cin, str);  // Get the input from the user and store it in str

  string str_a = "";  // Create a string to store the output
  for (char c : str) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      // If the character is a vowel, add it to the output
      str_a += c;
    }
  }
  cout << str_a;  // Print the output
  return 0;
}