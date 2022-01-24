#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr double INF_D = 1.0e-20;
constexpr double TOL = 1.0e-5;
constexpr int INF_I = 1 << 30;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  auto judge_ave = [&](double x) -> bool {
    vector<vector<double> > dp(n + 1, vector<double>(2, -INF_D));
    dp[0][1] = 0.0;
    for (int i = 0; i < n; ++i) {
      dp[i + 1][0] = dp[i][1];
      dp[i + 1][1] = max(dp[i][0], dp[i][1]) + a[i] - x;
    }
    return max(dp[n][0], dp[n][1]) >= 0.0;
  };

  auto judge_med = [&](int x) -> bool {
    vector<vector<int> > dp(n + 1, vector<int>(2, -INF_I));
    dp[0][1] = 0;
    for (int i = 0; i < n; ++i) {
      dp[i + 1][0] = dp[i][1];
      dp[i + 1][1] = max(dp[i][0], dp[i][1]) + (a[i] >= x ? 1 : -1);
    }
    return max(dp[n][0], dp[n][1]) > 0;
  };

  double ld = 0.0, rd = 1.1e9;
  while (rd - ld > TOL) {
    double md = (ld + rd) / 2;
    if (judge_ave(md)) ld = md;
    else rd = md;
  }

  int l = 0, r = 1000000001;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (judge_med(m)) l = m;
    else r = m;
  }

  printf("%.10f\n%d\n", ld, l);
  return 0;
}
