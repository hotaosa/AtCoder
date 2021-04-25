#include <iostream>

int main() {
  int a, b, c;
  std::cin >> a >> b >> c;
  std::cout << (a * a + b * b < c * c ? "Yes" : "No") << std::endl;
  return 0;
}
