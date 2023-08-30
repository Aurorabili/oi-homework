// without IDE

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  using namespace std;

  vector<int> nums;
  int num;
  while (cin >> num) {
    nums.push_back(num);
  }

  reverse(nums.begin(), nums.end());
  for (auto num : nums) {
    cout << num << ' ';
  }
  return 0;
}