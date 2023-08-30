#include <cmath>
#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int main() {
  int a, maxn = -INF;  // 1. Define two variables: a is the input number, maxn is the maximum number. We set maxn to -INF to avoid the case where the input is all negative numbers.
  while (cin >> a) {  // 2. Input a number a.
    maxn = max(maxn, a);  // 3. Compare the number a with maxn, and update the value of maxn.
  }
  
  cout << maxn;  // 4. Output the result.
  return 0;
}
