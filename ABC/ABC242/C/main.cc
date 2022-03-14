#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;  
  vector<vector<mint> > dp(n, vector<mint>(10, 0));
  for (int i = 1; i <= 9; ++i) dp[0][i] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 1; j <= 9; ++j) {
      for (int k = max(1, j - 1); k <= min(9, j + 1); ++k) {
        dp[i + 1][k] += dp[i][j];
      }
    }
  }
  mint res = 0;
  for (int i = 1; i <= 9; ++i) res += dp[n - 1][i];
  cout << res.val() << endl;
  return 0;
}
