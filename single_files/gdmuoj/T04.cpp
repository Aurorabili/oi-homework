#include <iostream>
#include <string>

using namespace std;

int main() {
  char c; // Declare character variable
  int v = 4; // Declare integer variable and initialize it to 4
  while ((c = getchar()) != EOF) { // While the input character is not end of file
    cout << ((isalpha(c + v)) ? char(c + v) : char(c + v - 26)); // Print the character and if the character is not a letter, subtract 26
  }
  return 0;
}