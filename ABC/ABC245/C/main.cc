#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto &p : a) cin >> p;
  for (auto &p : b) cin >> p;

  vector<vector<bool> > dp(n, vector<bool>(2, false));
  dp[0][0] = dp[0][1] = true;

  for (int i = 0; i < n - 1; ++i) {
    if (dp[i][0]) {
      if (abs(a[i] - a[i + 1]) <= k) dp[i + 1][0] = true;
      if (abs(a[i] - b[i + 1]) <= k) dp[i + 1][1] = true;
    }
    if (dp[i][1]) {
      if (abs(b[i] - a[i + 1]) <= k) dp[i + 1][0] = true;
      if (abs(b[i] - b[i + 1]) <= k) dp[i + 1][1] = true;
    }
  }

  cout << (dp[n - 1][0] || dp[n - 1][1] ? "Yes" : "No" ) << endl;
  return 0;
}
