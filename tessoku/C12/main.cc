#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m, c;
  cin >> n >> m >> c;

  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (n, vector<int>(c, m)));  
  dp[0][0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k < c; ++k) {
        chmin(dp[i][j][k], dp[i - 1][j][k]);
        if (i < n && k < c - 1) {
          int cnt = 0;
          for (int id = 0; id < m; ++id) {
            if (a[id] <= i && b[id] > i && a[id] > j) ++cnt;
          }
          chmin(dp[i][i][k + 1], dp[i][j][k] + cnt);
        }
      }
    }
  }

  int res = m;
  for (int i = 0; i < n; ++i) chmin(res, dp[n][i][c - 1]);
  res = m - res;
  cout << res << endl;
  return 0;
}
