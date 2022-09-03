#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<long long> > dp(n + 1, vector<long long>(m + 1, -(1LL << 60)));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j < m) chmax(dp[i + 1][j + 1], dp[i][j] + a[i] * (j + 1));
    }
  }

  cout << dp[n][m] << endl;  
  return 0;
}
