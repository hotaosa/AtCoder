#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, k, d;
  cin >> n >> k >> d;

  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  
  vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> > (k + 1, vector<long long>(d, -1)));
  dp[0][0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int c = 0; c <= k; ++c) {
      for (int m = 0; m < d; ++m) {
        if (dp[i][c][m] == -1) continue;
        chmax(dp[i + 1][c][m], dp[i][c][m]);
        if (c < k) chmax(dp[i + 1][c + 1][(m + a[i]) % d], dp[i][c][m] + a[i]);
      }
    }
  }

  cout << dp[n][k][0] << endl;  
  return 0;
}
