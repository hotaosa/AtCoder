#include <iostream>
#include <vector>

int main() {
  constexpr long long INF = 1LL << 60;
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> x(n), y(n);
  long long x_ma = -INF, x_mi = INF, y_ma = -INF, y_mi = INF;
  for (int i = 0; i < n; ++i) {
    long long xx, yy;
    std::cin >> xx >> yy;
    x[i] = xx - yy;
    x_ma = std::max(x_ma, x[i]);
    x_mi = std::min(x_mi, x[i]);
    y[i] = xx + yy;
    y_ma = std::max(y_ma, y[i]);
    y_mi = std::min(y_mi, y[i]);
  }

  while (q--) {
    int qu;
    std::cin >> qu;
    --qu;
    long long res = 0LL;
    res = std::max(res, std::abs(x[qu] - x_ma));
    res = std::max(res, std::abs(x[qu] - x_mi));
    res = std::max(res, std::abs(y[qu] - y_ma));
    res = std::max(res, std::abs(y[qu] - y_mi));
    std::cout << res << std::endl;
  }

  return 0;
}

