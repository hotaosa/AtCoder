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
  vector<double> x(n + m), y(n + m);
  for (int i = 0; i < n + m; ++i) cin >> x[i] >> y[i];

  const int mask = (1 << (n + m)) - (1 << n);
  auto velocity = [&](int bit) -> double {
    return (double)(1 << (__builtin_popcount(bit & mask)));
  };

  auto dist = [&](double xa, double ya, double xb, double yb) -> double {
    double dx = xa - xb;
    double dy = ya - yb;
    return sqrtl(dx * dx + dy * dy);
  };

  auto all_visited = [&](int bit) -> bool {
    return __builtin_popcount(bit & ((1 << n) - 1)) == n;
  };

  const double INF = 1.0e+30;
  double res = INF;
  vector<vector<double> > dp(1 << (n + m), vector<double>(n + m, INF));
  for (int i = 0; i < n + m; ++i) dp[1 << i][i] = dist(0.0, 0.0, x[i], y[i]);

  for (int bit = 0; bit < (1 << (n + m)); ++bit) {
    for (int v = 0; v < n + m; ++v) {
      if (dp[bit][v] == INF) continue;
      for (int nv = 0; nv < n + m; ++nv) {
        if (bit & (1 << nv)) continue;
        chmin(dp[bit | (1 << nv)][nv], dp[bit][v] + dist(x[v], y[v], x[nv], y[nv]) / velocity(bit));
        if (all_visited(bit | (1 << nv))) chmin(res, dp[bit | (1 << nv)][nv] + dist(0.0, 0.0, x[nv], y[nv]) / velocity(bit | (1 << nv)));
      }
    }
  }

  printf("%.10f\n", res);
  return 0;
}
