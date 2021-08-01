#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  if (a && b) std::cout << "Alloy" << std::endl;
  else if (a) std::cout << "Gold" << std::endl;
  else std::cout << "Silver" << std::endl;
  return 0;
}
