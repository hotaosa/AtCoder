#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      res += i * 100 + j;
    }
  }
  std::cout << res << std::endl;
  return 0;
}
