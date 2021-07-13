#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> x(n), y(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];

  std::sort(x.begin(), x.end());
  std::sort(y.begin(), y.end());

  long long cx = x[n / 2];
  long long cy = y[n / 2];

  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    res += std::abs(cx - x[i]) + std::abs(cy - y[i]);
  }

  std::cout << res << std::endl;
  return 0;
}
