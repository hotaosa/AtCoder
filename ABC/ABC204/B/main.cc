#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    res += std::max(0, a - 10);
  }
  std::cout << res << std::endl;
  return 0;
}
