#include <iostream>

long long Floor(long long x, long long y) {
  long long z = (x % y + y) % y;
  return (x - z) / y;
}

int main() {
  long long a, m, l, r;
  std::cin >> a >> m >> l >> r;
  std::cout << Floor(r - a, m) - Floor(l - a - 1, m) << std::endl;
  return 0;
}