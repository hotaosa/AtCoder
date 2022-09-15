#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<long long> lim(n);
  for (int i = n - 1; i >= 0; --i) {
    lim[i] = x / a[i];
    x %= a[i];
  }

  vector<vector<long long> > dp(n + 1, vector<long long>(2, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (lim[i] == 0 && j == 0) dp[i + 1][0] += dp[i][j];
      else if (i < n - 1 && lim[i] + j == a[i + 1] / a[i]) dp[i + 1][1] += dp[i][j];
      else {
        dp[i + 1][0] += dp[i][j];
        dp[i + 1][1] += dp[i][j];
      }
    }
  }
  cout << dp[n][0] << endl;
  return 0;
}
