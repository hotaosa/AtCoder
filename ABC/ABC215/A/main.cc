#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  std::cout << (s == "Hello,World!" ? "AC" : "WA") << std::endl;
  return 0;
}
