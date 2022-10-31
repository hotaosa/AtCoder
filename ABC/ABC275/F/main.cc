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
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  const int INF = 1 << 30;
  vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (m + 1, vector<int>(2, INF)));
  dp[0][0][1] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      chmin(dp[i + 1][j][0], min(dp[i][j][0], dp[i][j][1] + 1));
      if (j + a[i] <= m) chmin(dp[i + 1][j + a[i]][1], min(dp[i][j][0], dp[i][j][1]));
    }
  }

  for (int i = 1; i <= m; ++i) {
    int res = min(dp[n][i][0], dp[n][i][1]);
    cout << (res < INF ? res : -1) << endl;
  }
  return 0;
}
