#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << std::max(0, b - a + 1) << std::endl;
  return 0;
}
