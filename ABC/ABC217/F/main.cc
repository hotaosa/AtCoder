#include <iostream>
#include <vector>

int main() {
  const long long MOD = 998244353LL;
  
  int n, m;
  std::cin >> n >> m;
  n *= 2;

  std::vector<std::vector<long long> > binom(n + 1, std::vector<long long>(n + 1, 0LL));
  binom[0][0] = 1LL;
  for (int i = 1; i <= n; ++i) {
    binom[i][0] = 1LL;
    binom[i][i] = 1LL;
    for (int j = 0; j < i - 1; ++j) {
      binom[i][j + 1] = (binom[i - 1][j] + binom[i - 1][j + 1]) % MOD;
    }
  }

  std::vector<std::vector<bool> > fr(n, std::vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    fr[a][b] = fr[b][a] = true;
  }

  std::vector<std::vector<long long> > dp(n, std::vector<long long>(n, 0LL));
  for (int dist = 1; dist < n; dist += 2) {
    for (int left = 0; left <= n - dist; ++left) {
      int right = left + dist;
      for (int pa = left + 1; pa <= right; pa += 2) {
        if (!fr[left][pa]) continue;
        long long v1 = (pa > left + 1 ? dp[left + 1][pa - 1] : 1LL);
        long long v2 = (pa < right ? dp[pa + 1][right] : 1LL);
        int cnt1 = (pa - left + 1) / 2;
        int cnt2 = (right - pa) / 2;
        dp[left][right] = (dp[left][right] + v1 * v2 % MOD * binom[cnt1 + cnt2][cnt1]) % MOD;
      }
    }
  }

  std::cout << dp[0][n - 1] << std::endl;  
  return 0;
}
