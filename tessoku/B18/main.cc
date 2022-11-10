#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<bool> > dp(n + 1, vector<bool>(s + 1, false));
  dp[0][0] = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= s; ++j) {
      if (!dp[i][j]) continue;
      dp[i + 1][j] = true;
      if (j + a[i] <= s) dp[i + 1][j + a[i]] = true;
    }
  }

  if (!dp[n][s]) {
    cout << "-1" << endl;
  } else {
    vector<int> res;
    int cur = s;
    for (int i = n - 1; i >= 0; --i) {
      if (cur - a[i] >= 0 && dp[i][cur - a[i]]) {
        res.push_back(i + 1);
        cur -= a[i];
      }
    }
    assert(cur == 0);
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for (auto r : res) cout << r << " ";
    cout << endl;
  }

  return 0;
}