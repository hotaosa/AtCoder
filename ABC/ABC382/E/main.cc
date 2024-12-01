#include <iomanip>
#include <iostream>
#include <vector>

int main() {
  int n, x;
  std::cin >> n >> x;

  std::vector<double> p(n), q(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    p[i] /= 100;
    q[i] = 1.0 - p[i];
  }

  std::vector<double> f(n + 1);
  f[0] = 1.0;
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j >= 0; --j) {
      f[j + 1] += f[j] * p[i];
      f[j] *= q[i];
    }
  }

  std::vector<double> dp(x + 1, 0.0);
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i] += dp[std::max(0, i - j)] * f[j];
    }
    dp[i] = (dp[i] + 1.0) / (1 - f[0]);
  }

  std::cout << std::setprecision(8) << dp[x] << "\n";
  return 0;
}