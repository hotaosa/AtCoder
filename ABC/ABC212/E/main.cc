#include <iostream>
#include <vector>

int main() {
  const long long MOD = 998244353LL;
  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<std::vector<int> > unconnected(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    unconnected[--u].push_back(--v);
    unconnected[v].push_back(u);
  }

  std::vector<std::vector<long long> > dp(k + 1, std::vector<long long>(n, 0LL));
  dp[0][0] = 1LL;
  for (int i = 1; i <= k; ++i) {
    long long sum = 0LL;
    for (int j = 0; j < n; ++j) sum = (sum + dp[i - 1][j]) % MOD;
    for (int j = 0; j < n; ++j) {
      dp[i][j] = sum - dp[i - 1][j];
      for (int v : unconnected[j]) dp[i][j] -= dp[i - 1][v];
      while (dp[i][j] < 0LL) dp[i][j] += MOD;
    }
  }

  std::cout << dp[k][0] << std::endl;
  return 0;
}
