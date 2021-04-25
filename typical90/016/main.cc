#include <iostream>

int main() {
  long long n, a, b, c;
  std::cin >> n >> a >> b >> c;

  long long res = 1LL << 60;
  for (int i = 0; i < 10000 && a * i <= n; ++i) {
    for (int j = 0; j < 10000 - i && a * i + b * j <= n; ++j) {
      long long m = n - a * i - b * j;
      if (m % c != 0) continue;
      res = std::min(res, i + j + m / c);
    }
  }
  std::cout << res << std::endl;
  return 0;
}
