#include <iostream>
#include <vector>

int main() {
  const long long MOD = 1000000007LL;
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > is_good(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) std::cin >> is_good[i][j];

  std::vector<std::vector<long long> > dp(n, std::vector<long long>(1 << n, 0LL));
  for (int i = 0; i < n; ++i) if (is_good[0][i]) ++dp[0][(1 << i)];
  
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (dp[i][j]) {
        for (int k = 0; k < n; ++k) {
          if (is_good[i + 1][k] && !(j & (1 << k))) {
            dp[i + 1][j + (1 << k)] = (dp[i + 1][j + (1 << k)] + dp[i][j]) % MOD;
          }
        }
      }
    }
  }
  std::cout << dp[n - 1][(1 << n) - 1] << std::endl;
  return 0;
}
