#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m;
  long long a, b, c, d, e, f;
  cin >> n >> m >> a >> b >> c >> d >> e >> f;

  set<pair<long long, long long> > obstacle;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    obstacle.insert({x, y});
  }

  auto exist_obstacle = [&](long long x, long long y) -> bool {
    return obstacle.count({x, y});
  };

  vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> >(n + 1, vector<mint>(n + 1, 0)));
  dp[0][0][0] = 1;

  for (int sum = 1; sum <= n; ++sum) {
    for (int i = 0; i <= sum; ++i) {
      for (int j = 0; j <= sum - i; ++j) {
        int k = sum - i - j;
        long long x = a * i + c * j + e * k;
        long long y = b * i + d * j + f * k;
        if (exist_obstacle(x, y)) continue;
        if (i > 0) dp[sum][i][j] += dp[sum - 1][i - 1][j];
        if (j > 0) dp[sum][i][j] += dp[sum - 1][i][j - 1];
        if (k > 0) dp[sum][i][j] += dp[sum - 1][i][j];
      }
    }
  }

  mint res = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n - i; ++j) {
      res += dp[n][i][j];
    }
  }
  cout << res.val() << endl;
  return 0;
}
