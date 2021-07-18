#include <iostream>

int main() {
  int n, a, x, y;
  std::cin >> n >> a >> x >> y;
  int res = x * n;
  res -= std::max(n - a, 0) * (x - y);
  std::cout << res << std::endl;
  return 0;
}
