#include <iostream>

int main() {
  constexpr int ma = 9999;
  constexpr int INF = 1 << 30;
  long long n, a, b, c;
  std::cin >> n >> a >> b >> c;
  int res = INF;
  for (int i = 0; i <= ma; ++i) {
    for (int j = 0; j <= ma - i; ++j) {
      long long m = n - a * i - b * j;
      if (m < 0LL || m % c) continue;
      int k = m / c;
      res = std::min(res, i + j + k);
    }
  }
  std::cout << res << std::endl;
  return 0;  
}
