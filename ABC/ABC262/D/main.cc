#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  mint res = 0;
  for (int i = 1; i <= n; ++i) {
    vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> >(i + 1, vector<mint>(i, 0)));
    dp[0][0][0] = 1;
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k <= i; ++k) {
        for (int l = 0; l < i; ++l) {
          dp[j + 1][k][l] += dp[j][k][l];
          if (k < i) dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
        }
      }
    }
    res += dp[n][i][0];
  }
  cout << res.val() << endl;
  return 0;
}
