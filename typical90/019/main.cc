#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

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
  vector<vector<long long> > dp(n, vector<long long>(n, INF));
  for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = abs(a[i] - a[i + 1]);

  for (int d = 3; d < n; d += 2) {
    for (int l = 0; l < n - d; ++l) {
      int r = l + d;
      for (int p = l + 1; p <= r; p += 2) {           
        if (p == l + 1) chmin(dp[l][r], dp[p + 1][r] + dp[l][p]);
        else if (p == r) chmin(dp[l][r], dp[l + 1][r - 1] + abs(a[l] - a[r]));        
        else chmin(dp[l][r], dp[l + 1][p - 1] + dp[p + 1][r] + abs(a[l] - a[p]));        
      }            
    }    
  }

  cout << dp[0][n - 1] << endl;
  return 0;
}
