#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  long long x, y;
  cin >> n >> x >> y;
  vector<long long> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  vector<vector<long long> > dp(n + 1, vector<long long>(1 << n, INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (dp[i][j] == INF) continue;
      for (int k = 0; k < n; ++k) {
        if (j & (1 << k)) continue;
        long long add = 0;
        for (int l = k + 1; l < n; ++l) if (j & (1 << l)) add += y;        
        chmin(dp[i + 1][j | (1 << k)], dp[i][j] + add + abs(a[k] - b[i]) * x);
      }
    }
  }

  cout << dp[n][(1 << n) - 1] << endl;
  return 0;
}
