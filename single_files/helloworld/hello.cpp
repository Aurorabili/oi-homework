#include <iostream>
#include <ostream>
#include <set>
#include <string>
#include <vector>

int len(std::set<std::string> s) { return s.size(); }

int main() {
  std::set<std::string> v = {"Hello", "World"};

  std::cout << len(v) << std::endl;

  for (auto s : v) {
    std::cout << s << std::endl;
  }

  return 0;
}