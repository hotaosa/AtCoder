#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > c(n + 1, vector<int>(n + 1, n));
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    chmin(c[x][y], z);
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 1; j <= n; ++j) {
      chmin(c[i][j], c[i + 1][j]);
    }
  }

  vector<vector<long long> > dp(n + 1, vector<long long>(1 << n, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      vector<int> cnt(n + 1, 0);
      for (int k = 1; k <= n; ++k) {
        if (j & (1 << (k - 1))) ++cnt[k];
        cnt[k] += cnt[k - 1];
      }
      for (int k = 1; k <= n; ++k) {
        if (j & (1 << (k - 1))) continue;
        int nx = j | (1 << (k - 1));
        bool ok = true;
        for (int l = k; l <= n; ++l) ok &= cnt[l] < c[i + 1][l];
        if (ok) dp[i + 1][nx] += dp[i][j];
      }
    }
  }

  cout << dp[n][(1 << n) - 1] << endl;
  return 0;
}
