#include <iostream>

int main() {
  int r, d, res;
  std::cin >> r >> d >> res;
  for (int i = 0; i < 10; ++i) {
    res = r * res - d;
    std::cout << res << std::endl;
  }
  return 0;
}
