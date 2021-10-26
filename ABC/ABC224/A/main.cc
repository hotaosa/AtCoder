#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int len = (int)s.length();
  std::cout << (s.substr(len - 2, 2) == "er" ? "er" : "ist") << std::endl;
  return 0;
}
