#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int res = -1;
  for (int i = 1; i <= n; ++i) {
    int a;
    std::cin >> a;
    if (a == 1) res = i;
  }
  std::cout << res << std::endl;
  return 0;
}
