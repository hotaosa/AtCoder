#include <iostream>
#include <string>
#include <set>

int main() {
  std::set<std::string> se;
  for (int i = 0; i < 4; ++i) {
    std::string s;
    std::cin >> s;
    se.insert(s);
  }

  std::cout << (se.size() == 4 ? "Yes" : "No") << std::endl;
  return 0;
}
