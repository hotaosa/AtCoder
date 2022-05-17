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
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<vector<long long> > > dp(2, vector<vector<long long> > (n, vector<long long>(2, INF)));
  dp[0][0][0] = 0;
  dp[1][0][1] = a[0];

  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j < n; ++j) {
      chmin(dp[i][j][0], dp[i][j - 1][1]);
      chmin(dp[i][j][1], dp[i][j - 1][0] + a[j]);
      chmin(dp[i][j][1], dp[i][j - 1][1] + a[j]);
    }
  }

  cout << min(dp[0][n - 1][1], min(dp[1][n - 1][0], dp[1][n - 1][1])) << endl;
  return 0;
}
