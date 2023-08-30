#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &str,
                               const std::string &delim) {
  std::vector<std::string> res;
  if ("" == str) return res;

  std::string word = "";
  for (std::string::size_type i = 0; i < str.size(); i++) {
    if (delim.find(str[i]) != std::string::npos) {
      if (word != "") res.push_back(word);
      word = "";
    } else {
      word += str[i];
    }
  }
  if (word != "") res.push_back(word);

  return res;
}

int main() {
  using namespace std;
  
  string str;
  getline(cin, str);
  int insert_num;
  cin >> insert_num;
  vector<int> nums;
  for (auto num : split(str, " ")) {
    int n = stoi(num);
    nums.push_back(n);
  }
  const auto cmp = [nums](int a, int b) {
    return (nums[0] > nums[1] ? (a < b) : (a > b));
  };

  for (auto it = nums.begin(); it != nums.end(); it++) {
    if (cmp(*it, insert_num)) {
      nums.insert(it, insert_num);
      break;
    }
  }

  for_each(nums.begin(), nums.end(), [](int num) { cout << num << " "; });

  return 0;
}