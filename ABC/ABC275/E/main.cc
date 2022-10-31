#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<mint> > dp(k + 1, vector<mint>(n + 1, 0));
  for (int i = 0; i <= k; ++i) dp[i][n] = 1;

  for (int i = k - 1; i >= 0; --i) {
    for (int j = 0; j < n; ++j) {
      for (int d = 1; d <= m; ++d) {
        if (j + d <= n) dp[i][j] += dp[i + 1][j + d] / m;
        else dp[i][j] += dp[i + 1][n - (j + d - n)] / m;
      }
    }
  }

  cout << dp[0][0].val() << endl;  
  return 0;
}
