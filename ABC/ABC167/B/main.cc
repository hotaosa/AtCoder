#include <iostream>

int main() {
  int a, b, c, k;
  std::cin >> a >> b >> c >> k;

  int res = 0;
  res += std::min(a, k);
  k -= res + b;
  if (k > 0) res -= k;
  std::cout << res << std::endl;
  return 0;
}
