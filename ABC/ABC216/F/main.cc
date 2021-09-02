#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const int MOD = 998244353;
  
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) std::cin >> vp[i].first;
  for (int i = 0; i < n; ++i) std::cin >> vp[i].second;

  std::sort(vp.begin(), vp.end());
  std::vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    a[i + 1] = vp[i].first;
    b[i + 1] = vp[i].second;
  }

  int ma = a.back();
  std::vector<std::vector<int> > dp(n + 1, std::vector<int>(ma + 1, 0));
  dp[0][0] = 1;

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= ma; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - b[i] >= 0) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - b[i]]) % MOD;
        if (j <= a[i]) res = (res + dp[i - 1][j - b[i]]) % MOD;
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}
