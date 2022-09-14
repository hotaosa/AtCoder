#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  set<int> se;
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    se.insert(a);
  }

  if (k >= m) {
    bool possible = true;
    for (auto s : se) {
      bool ok = false;
      for (int i = 1; i < m; ++i) {
        ok |= !se.count(s + i);
      }
      possible &= ok;
    }
    if (!possible) { cout << "-1" << endl; return 0; }
  }

  auto judge = [&](long double val) -> bool {
    vector<long double> dp(n + 1);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (se.count(i)) dp[i] = val;
      else dp[i] = (dp[i + 1] - dp[min(n, i + m + 1)]) / m + 1.0;
      dp[i] += dp[i + 1];
    }
    return dp[0] - dp[1] >= val;
  };

  long double l = 1.0, r = 1.0e20;
  while (r - l > 1.0e-5) {
    long double mid = sqrt(l * r);
    if (judge(mid)) l = mid;
    else r = mid;
  }

  printf("%.6Lf\n", l);
  return 0;
}
