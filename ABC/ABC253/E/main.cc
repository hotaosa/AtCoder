#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  
  if (k == 0) {
    cout << mint(m).pow(n).val() << endl;
    return 0;
  }

  vector<vector<mint> > dp(n, vector<mint>(m + 1, 0)), sum(n, vector<mint>(m + 1, 0));
  for (int i = 1; i <= m; ++i) { dp[0][i] = 1; sum[0][i] = sum[0][i - 1] + 1; }

  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int l = j - k;
      if (l >= 0) dp[i][j] += sum[i - 1][l];
      int r = j + k - 1;
      if (r < m) dp[i][j] += sum[i - 1][m] - sum[i - 1][r];
      sum[i][j] = sum[i][j - 1] + dp[i][j];
    }    
  }

  cout << sum[n - 1][m].val() << endl;
  return 0;
}
