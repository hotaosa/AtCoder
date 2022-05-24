#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  vector<vector<mint> > dp(n + 1, vector<mint>(m + 1, 0));
  dp[0][0] = 1;  
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
      if (i > 0 && j > 0 && a[i - 1] != b[j - 1]) dp[i][j] -= dp[i - 1][j - 1];      
    }
  }

  cout << dp[n][m].val() << endl;  
  return 0;
}
