#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) cin >> q[i];

  vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> >(d + 1, vector<mint>(d + 1, 0)));
  dp[0][0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    vector<vector<mint> > ds1 = dp[i - 1];
    vector<vector<mint> > ds2 = dp[i - 1];

    auto sum1 = [&](int sr, int sc) -> void {
      for (int r = sr, c = sc; r < d && c < d; ++r, ++c) ds1[r + 1][c + 1] += ds1[r][c];
    };
    auto sum2 = [&](int sr, int sc) -> void {
      for (int r = sr, c = sc; r > 0 && c < d; --r, ++c) ds2[r - 1][c + 1] += ds2[r][c];
    };

    int sr = 0, sc = d;
    while (sc > 0) sum1(sr, --sc);
    while (++sr < d) sum1(sr, sc);
    sc = d;
    while (sc > 0) sum2(sr, --sc);
    while (sr > 0) sum2(--sr, sc);
    
    int diff = abs(p[i - 1] - q[i - 1]);
    for (int j = 0; j <= d; ++j) {
      for (int k = 0; k <= d; ++k) {
        if (j - 1 >= 0 && k - diff - 1 >= 0) dp[i][j][k] += ds1[j - 1][k - diff - 1];
        if (j - diff - 1 >= 0 && k - 1 >= 0) dp[i][j][k] += ds1[j - diff - 1][k - 1];
        int j2 = j - diff, k2 = k;
        if (j2 < 0) {
          k2 += j2;
          j2 = 0;
        }
        if (k2 >= 0) {
          dp[i][j][k] += ds2[j2][k2];
          j2 = j + 1;
          k2 = k - diff - 1;
          if (j2 <= d && k2 >= 0) dp[i][j][k] -= ds2[j2][k2];
        }
      }
    }
  }

  mint res = 0;
  for (int i = 0; i <= d; ++i) {
    for (int j = 0; j <= d; ++j) {
      res += dp[n][i][j];
    }
  }
  cout << res.val() << endl;
  return 0;
}
