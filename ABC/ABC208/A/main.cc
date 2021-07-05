#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << (b >= a && b <= a * 6 ? "Yes" : "No") << std::endl;
  return 0;
}
