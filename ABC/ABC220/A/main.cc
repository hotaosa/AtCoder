#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;

  int res = (a + c - 1) / c * c;
  std::cout << (res <= b ? res : -1) << std::endl;
  return 0;
}
