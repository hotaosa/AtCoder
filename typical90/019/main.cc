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
  n *= 2;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<int> > dp(n, vector<int>(n, 1 << 28));
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = abs(a[i] - a[i + 1]);

  for (int d = 3; d < n; d += 2) {
    for (int l = 0; l + d < n; ++l) {
      int r = l + d;
      chmin(dp[l][r], dp[l + 2][r] + dp[l][l + 1]);
      chmin(dp[l][r], dp[l + 1][r - 1] + abs(a[l] - a[r]));
      for (int m = l + 3; m < r; m += 2) {
        chmin(dp[l][r], dp[l + 1][m - 1] + dp[m + 1][r] + abs(a[l] - a[m]));
      }
    }
  }    

  cout << dp[0][n - 1] << endl;  
  return 0;
}
