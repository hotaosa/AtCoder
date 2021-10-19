#include <iostream>

int main() {
  int x;
  std::cin >> x;
  std::cout << (x > 0 && x % 100 == 0 ? "Yes" : "No") << std::endl;
  return 0;
}
