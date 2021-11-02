#include <iostream>
#include <string>
#include <set>

int main() {
  int n;
  std::cin >> n;
  std::set<std::string> se;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    if (se.insert(s).second) std::cout << i + 1 << std::endl;
  }
  return 0;
}
