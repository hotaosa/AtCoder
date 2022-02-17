#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string x;
  cin >> n >> x;

  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) dp[i] = dp[i % __builtin_popcount(i)] + 1;

  int cnt = 0;
  for (char c : x) if (c == '1') ++cnt;

  reverse(x.begin(), x.end());
  vector<int> res(n);
  int tot1 = 0, tot2 = 0, p1 = 1, p2 = 1;

  for (int i = 0; i < n; ++i) {
    if (x[i] == '1') {
      tot1 = (tot1 + p1) % (cnt + 1);
      if (cnt > 1) tot2 = (tot2 + p2) % (cnt - 1);
    }
    p1 = (p1 * 2) % (cnt + 1);
    if (cnt > 1) p2 = (p2 * 2) % (cnt - 1);
  }

  p1 = 1;
  p2 = 1;
  for (int i = 0; i < n; ++i) {
    if (x[i] == '1') {
      if (cnt == 1) res[n - 1 - i] = 0;
      else res[n - 1 - i] = dp[(tot2 - p2 + cnt - 1) % (cnt - 1)] + 1;
    } else {
      res[n - 1 - i] = dp[(tot1 + p1 + cnt + 1) % (cnt + 1)] + 1;
    }
    p1 = (p1 * 2) % (cnt + 1);
    if (cnt > 1) p2 = (p2 * 2) % (cnt - 1);
  }

  for (auto &p : res) cout << p << endl;    
  return 0;
}
