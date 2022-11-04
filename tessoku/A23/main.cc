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

  vector<int> bit(m, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int a;
      cin >> a;
      if (a == 1) bit[i] |= 1 << j;
    }
  }

  const int INF = 1 << 30;
  vector<vector<int> > dp(m + 1, vector<int>(1 << n, INF));
  dp[0][0] = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      chmin(dp[i + 1][j], dp[i][j]);
      chmin(dp[i + 1][j | bit[i]], dp[i][j] + 1);
    }
  }

  int res = dp.back().back();
  cout << (res < INF ? res : -1) << endl;
  return 0;
}
