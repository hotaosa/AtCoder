#include <iostream>

int main() {
  int h, w;
  std::cin >> h >> w;

  if (h < 2 || w < 2) std::cout << h * w << std::endl;
  else std::cout << (h + 1) / 2 * ((w + 1) / 2) << std::endl;
  return 0;
}
