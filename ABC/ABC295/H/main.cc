#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n, m;
  cin >> n >> m;
  vector<string> x(n);
  for (auto &p : x) cin >> p;

  auto BSet = [&](int b, int d, int x) -> int {
    assert(x == 0 || x == 1);
    assert(d < m);
    if (x) {
      return b & ((1 << m) - 1);
    } else {
      return b & ~(1 << d);
    }
  };

  vector dp(1 << m, vector<mint>(2, 0));
  dp.back()[1] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      vector d(1 << m, vector<mint>(2, 0));
      swap(d, dp);
      for (int k = 0; k < (1 << m); ++k) {
        for (int l = 0; l < 2; ++l) {
          if (d[k][l] == 0) continue;
          for (int c = 0; c < 2; ++c) {
            if (x[i][j] - '0' == (c ^ 1)) continue;
            if (c && !(k >> j & 1) && (j && !l)) continue;
            int nk = BSet(k, j, c);
            int nl = ((!j || l) && c) ? 1 : 0;
            dp[nk][nl] += d[k][l];
          }
        }
      }
    }
  }

  mint res = 0;
  for (auto d : dp) res += d[0] + d[1];
  cout << res.val() << endl;
  return 0;
}
