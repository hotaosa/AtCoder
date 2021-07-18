#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  int x = (a + b) / 2;
  int y = a - x;
  std::cout << x << " " << y << std::endl;
  return 0;
}
