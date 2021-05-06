#include <iostream>

int main() {
  char s, t;
  std::cin >> s >> t;
  char res = t;
  if (s == 'Y') res = 'A' + res - 'a';
  std::cout << res << std::endl;
  return 0;
}
