#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> pos(n), p(n), q(n);
  for (int i = 0; i < n; ++i) { cin >> p[i]; --p[i]; }
  for (int i = 0; i < n; ++i) { cin >> q[i]; --q[i]; }
  for (int i = 0; i < n; ++i) pos[p[i]] = q[i];  

  vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> > (k + 1, vector<mint>(n + 1, 0)));
  dp[0][0][n] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int mi = 0; mi <= n; ++mi) {
        dp[i + 1][j][min(mi, pos[i])] += dp[i][j][mi];
        if (pos[i] < mi && j < k) dp[i + 1][j + 1][mi] += dp[i][j][mi];
      }
    }
  }

  mint res = 0;
  for (auto cur : dp[n][k]) res += cur;
  cout << res.val() << endl;
  return 0;
}
