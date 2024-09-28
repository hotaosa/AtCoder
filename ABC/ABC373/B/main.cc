#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  int res = 0;
  auto it1 = std::find(std::begin(s), std::end(s), 'A');
  for (int i = 1; i < 26; ++i) {
    auto it2 = std::find(std::begin(s), std::end(s), char('A' + i));
    res += std::abs(std::distance(it1, it2));
    it1 = it2;
  }

  std::cout << res << std::endl;
  return 0;
}
