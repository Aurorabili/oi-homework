#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

std::vector<int>::iterator binary_find(std::vector<int>::iterator begin,
                                       std::vector<int>::iterator end, int n) {
  if (begin == end) {
    return end;
  }
  auto mid = begin + (end - begin) / 2;
  if (*mid == n) {
    return mid;
  } else if (*mid < n) {
    return binary_find(begin, mid, n);
  } else {
    return binary_find(mid + 1, end, n);
  }
}

int main() {
  using namespace std;

  string str;
  vector<int> numbers;
  getline(cin, str);

  // split str to numbers
  string tmp_num_str = "";
  for (auto c : str) {
    if (c == ' ') {
      numbers.push_back(stoi(tmp_num_str));
      tmp_num_str = "";
    } else {
      tmp_num_str += c;
    }
  }
  numbers.push_back(stoi(tmp_num_str));

  int n;
  cin >> n;
  auto it = binary_find(numbers.begin(), numbers.end(), n);
  if (it != numbers.end()) {
    cout << distance(numbers.begin(), it) + 1 << endl;
  } else {
    cout << "无此数" << endl;
  }
  return 0;
}