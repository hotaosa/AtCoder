#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m;
  cin >> n >> m;

  mint dp[n + 1][m + 2][m + 2][m + 2];
  dp[0][m + 1][m + 1][m + 1] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m + 1; ++j) {
      for (int k = 1; k <= m + 1; ++k) {
        for (int l = 1; l <= m + 1; ++l) {
          for (int nx = 1; nx <= m; ++nx) {
            if (nx <= j) dp[i + 1][nx][k][l] += dp[i][j][k][l];
            else if (nx <= k) dp[i + 1][j][nx][l] += dp[i][j][k][l];
            else if (nx <= l) dp[i + 1][j][k][nx] += dp[i][j][k][l];
          }
        }
      }
    }
  }

  mint res = 0;
  for (int i = 1; i <= m - 2; ++i) {
    for (int j = i + 1; j <= m - 1; ++j) {
      for (int k = j + 1; k <= m; ++k) res += dp[n][i][j][k];
    }
  }
  cout << res.val() << endl;    
  return 0;
}
