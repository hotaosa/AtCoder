#include <iostream>

int main() {
  int n, y;
  std::cin >> n >> y;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n - i; ++j) {
      int k = n - i - j;
      if (10000 * i + 5000 * j + 1000 * k == y) {
        std::cout << i << " " << j << " " << k << std::endl;
        return 0;
      }
    }
  }
  std::cout << "-1 -1 -1" << std::endl;
  return 0;
}
