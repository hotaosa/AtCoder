#include <iostream>

int main() {
  int h, w;
  std::cin >> h >> w;
  if (h == 1 || w == 1) std::cout << h * w << std::endl;
  else std::cout << ((h + 1) / 2) * ((w + 1) / 2) << std::endl;
  return 0;
}
