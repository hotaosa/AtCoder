#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<mint> > dp(n + 1, vector<mint>(s + 2, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= s; ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][min(j + a[i], s + 1)] += dp[i][j] / 2;
    }
  }
  mint res = dp[n][s];
  for (int i = 0; i < n; ++i) res *= 2;
  cout << res.val() << endl;
  return 0;
}
