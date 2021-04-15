#include <bits/stdc++.h>

int main() {
  double r, x, y;
  std::cin >> r >> x >> y;

  int res;
  if (x * x + y * y < r * r) res = 2;
  else res = std::ceil(std::sqrt(x * x + y * y) / r);
  std::cout << res << std::endl;
  return 0;
}
