#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<double> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  vector<vector<double> > dist(n, vector<double>(n, 0.0));
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double dx = x[i] - x[j], dy = y[i] - y[j];
      dist[i][j] = dist[j][i] = sqrt(dx * dx + dy * dy);
    }
  }

  const double INF = 1.0e20;
  vector<vector<vector<double> > > dp(n, vector<vector<double> > (1 << n, vector<double>(n, INF)));
  for (int i = 0; i < n; ++i) dp[i][1 << i][i] = 0;

  for (int s = 0; s < n; ++s) {
    for (int v = 1; v < (1 << n); ++v) {
      for (int cur = 0; cur < n; ++cur) {
        if (!(v & (1 << cur))) continue;
        for (int nx = 0; nx < n; ++nx) {
          if (v & (1 << nx)) continue;
          chmin(dp[s][v | (1 << nx)][nx], dp[s][v][cur] + dist[cur][nx]);
        }
      }
    }
  }

  double res = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      chmin(res, dp[i][(1 << n) - 1][j] + dist[i][j]);
    }
  }

  printf("%.5f\n", res);
  return 0;
}
