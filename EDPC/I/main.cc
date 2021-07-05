#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<double> p(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> p[i];
  std::vector<std::vector<double> > dp(n + 1, std::vector<double>(n + 1, 0.0));

  dp[0][0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] += dp[i - 1][j] * (1.0 - p[i]);
      if (j > 0) dp[i][j] += dp[i - 1][j - 1] * p[i];
    }
  }

  double res = 0.0;
  for (int i = (n + 1) / 2; i <= n; ++i) res += dp[n][i];
  printf("%.10f\n", res);
  return 0;
}
