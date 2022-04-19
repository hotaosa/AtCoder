#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n, p;
  cin >> n >> p;
  mint::set_mod(p);

  vector<vector<vector<mint> > > dp(n, vector<vector<mint> > (n + 2, vector<mint>(2, 0)));
  dp[0][0][1] = 1;
  dp[0][1][0] = 1;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n; ++j) {
      dp[i + 1][j][1] += dp[i][j][0] + dp[i][j][1];
      dp[i + 1][j + 1][0] += dp[i][j][0];
      dp[i + 1][j + 1][1] += dp[i][j][1] * 3;
      dp[i + 1][j + 2][0] += dp[i][j][1] * 2;
    }
  }

  for (int i = 1; i < n; ++i) cout << dp[n - 1][i][1].val() << " ";
  cout << endl;
  return 0;
}
