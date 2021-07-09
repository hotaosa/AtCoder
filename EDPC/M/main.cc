#include <iostream>
#include <vector>

int main() {
  const long long MOD = 1000000007LL;
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(k + 1, 0LL));
  dp[0][0] = 1LL;

  auto prefixSum = [&](int i) -> void {
    for (int j = 1; j <= k; ++j) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
  };

  auto retSum = [&](int i, int j, int k) -> long long {
    long long res = dp[i][k];
    if (j > 0) res -= dp[i][j - 1];
    while (res < 0) res += MOD;
    return res;
  };

  for (int i = 1; i <= n; ++i) {
    prefixSum(i - 1);
    for (int j = 0; j <= k; ++j) {
      dp[i][j] = retSum(i - 1, j - a[i], j);
    }
  }

  std::cout << dp[n][k] << std::endl;    
  return 0;
}
