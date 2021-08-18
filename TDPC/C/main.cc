#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int k;
  std::cin >> k;

  std::vector<double> rating(1 << k);
  for (int i = 0; i < (1 << k); ++i) std::cin >> rating[i];

  std::vector<std::vector<double> > dp(k + 1, std::vector<double>(1 << k, 0.0));
  for (int i = 0; i < (1 << k); ++i) dp[0][i] = 1.0;

  auto win_p = [&](int i, int j) -> double {
    return 1.0 / (1.0 + std::pow(10.0, (rating[j] - rating[i]) / 400.0));
  };

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < (1 << k); ++j) {
      int op = (j & (((1 << k) - 1) - ((1 << i) - 1)));
      op ^= (1 << (i - 1));
      while ((op & (1 << (i - 1))) ^ (j & (1 << (i - 1)))) {
        dp[i][j] += dp[i - 1][j] * dp[i - 1][op] * win_p(j, op);
        dp[i][op] += dp[i - 1][j] * dp[i - 1][op] * win_p(op, j);
        ++op;
      }
    }
  }
  
  for (int i = 0; i < (1 << k); ++i) printf("%.10f\n", dp[k][i]);
  return 0;  
}
