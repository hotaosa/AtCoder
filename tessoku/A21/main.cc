#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> p(n), a(n);
  for (int i = 0; i < n; ++i) { cin >> p[i] >> a[i]; --p[i]; }

  vector<vector<int> > dp(n, vector<int>(n, 0));
  for (int l = 0; l < n - 1; ++l) {
    for (int r = n - 1; r > l; --r) {
      if (p[l] > l && p[l] <= r) chmax(dp[l + 1][r], dp[l][r] + a[l]);
      else chmax(dp[l + 1][r], dp[l][r]);
      if (p[r] < r && p[r] >= l) chmax(dp[l][r - 1], dp[l][r] + a[r]);
      else chmax(dp[l][r - 1], dp[l][r]);
    }
  }

  int res = 0;
  for (int i = 0; i < n; ++i) chmax(res, dp[i][i]);
  cout << res << endl;  
  return 0;
}
