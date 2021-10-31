#include <iostream>
#include <set>

int main() {
  std::set<char> se;
  for (int i = 0; i < 3; ++i) {
    char c;
    std::cin >> c;
    se.insert(c);
  }

  if (se.size() == 1) std::cout << "1" << std::endl;
  else if (se.size() == 2) std::cout << "3" << std::endl;
  else std::cout << "6" << std::endl;
  return 0;
}
