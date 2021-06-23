#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  if (a + b == c * 2 || a + c == b * 2 || b + c == a * 2) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}
