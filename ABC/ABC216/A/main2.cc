#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  int y = s.back() - '0';

  if (s.length() == 3) std::cout << s[0];
  else std::cout << s[0] << s[1];
  if (y < 3) std::cout << '-';
  else if (y > 6) std::cout << '+';
  std::cout << std::endl;
  return 0;
}
