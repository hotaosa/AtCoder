#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  int res = a ^ b;
  std::cout << (res ? res : -1) << std::endl;
  return 0;
}
