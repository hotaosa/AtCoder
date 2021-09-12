#include <iostream>
#include <string>
#include <map>

int main() {
  std::map<int, int> ma;
  for (int i = 0; i < 3; ++i) {
    std::string s;
    std::cin >> s;
    ++ma[s[1] - 'A'];
  }

  if (ma[1] == 0) std::cout << "ABC" << std::endl;
  else if (ma[17] == 0) std::cout << "ARC" << std::endl;
  else if (ma[6] == 0) std::cout << "AGC" << std::endl;
  else std::cout << "AHC" << std::endl;
  return 0;
}
