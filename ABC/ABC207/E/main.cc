#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<vector<int> > modsum(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      modsum[i][j] = (modsum[i - 1][j] + a[i]) % j;
    }
  }

  vector<vector<int> > prev(n + 1, vector<int>(n + 1, -1));
  for (int i = 1; i <= n; ++i) prev[i][0] = 0;

  vector<vector<mint> > dp(n + 1, vector<mint>(n + 1, 0));
  dp[0][0] = 1;
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int ms = modsum[i][j];
      int p = prev[j][ms];
      if (p != -1) dp[i][j] = dp[p][j] + dp[p][j - 1];
      prev[j][ms] = i;
    }
  }

  mint res = 0;
  for (int i = 1; i <= n; ++i) res += dp[n][i];
  cout << res.val() << endl;
  return 0;
}
