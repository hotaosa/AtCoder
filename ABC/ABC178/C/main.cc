#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;

  vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> > (2, vector<mint>(2, 0)));
  dp[0][0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[i + 1][j][k] += dp[i][j][k] * 8;
        dp[i + 1][1][k] += dp[i][j][k];
        dp[i + 1][j][1] += dp[i][j][k];
      }
    }
  }

  cout << dp[n][1][1].val() << endl;  
  return 0;
}
