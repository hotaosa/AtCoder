#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << std::max(a + b, std::max(b + c, a + c)) << std::endl;
  return 0;
}
