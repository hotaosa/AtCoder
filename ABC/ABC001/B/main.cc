#include <iostream>

int main() {
  int m;
  std::cin >> m;

  if (m < 100) std::cout << "00" << std::endl;
  else if (m <= 5000) {
    if (m < 1000) std::cout << "0";
    std::cout << m / 100 << std::endl;
  } else if (m <= 30000) std::cout << m / 1000 + 50 << std::endl;
  else if (m <= 70000) std::cout << (m / 1000 - 30) / 5 + 80 << std::endl;
  else std::cout << "89" << std::endl;
  return 0;
}
