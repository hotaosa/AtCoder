#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;

  for (char c : s) {
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') continue;
    std::cout << c;
  }
  std::cout << std::endl;
  return 0;
}
