#include <iostream>
#include <string>

int main() {
  int res = 0;
  for (size_t i = 0; i < 12; ++i) {
    std::string s;
    std::cin >> s;
    if (size(s) == i + 1) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}