#include <iostream>
#include <cmath>

int main() {
  double x, y, z;
  std::cin >> x >> y >> z;
  double res = z * y / x;
  if (res == (double)std::floor(res)) res -= 1.0;
  std::cout << std::floor(res) << std::endl;
  return 0;
}
