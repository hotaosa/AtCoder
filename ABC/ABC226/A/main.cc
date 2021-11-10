#include <iostream>
#include <cmath>

int main() {
  double x;
  std::cin >> x;
  std::cout << std::floor(x) + (x - std::floor(x) >= 0.5 ? 1 : 0) << std::endl;
  return 0;
}
