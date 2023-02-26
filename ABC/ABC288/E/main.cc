#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool ChangeMin(T &a, const T &b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector c(n, vector<long long>(n, INF));
  for (int i = 0; i < n; ++i) cin >> c[i][i];
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      c[i][j] = min(c[i][j - 1], c[j][j]);
    }
  }

  vector<bool> must(n, false);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    must[--x] = true;
  }

  vector dp(n + 1, vector<long long>(n + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j] == INF) continue;
      if (!must[i]) {
        ChangeMin(dp[i + 1][j], dp[i][j]);
      }
      ChangeMin(dp[i + 1][j + 1], dp[i][j] + a[i] + c[i - j][i]);
    }
  }

  long long res = INF;
  for (int i = m; i <= n; ++i) {
    ChangeMin(res, dp[n][i]);
  }
  cout << res << endl;
  return 0;
}
