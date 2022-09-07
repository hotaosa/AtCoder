#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<long long> h(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> h[i];
  vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> >(k + 1, vector<long long>(k + 1, INF)));
  dp[0][0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int l = 0; l <= j; ++l) {
        chmin(dp[i][j][0], dp[i - 1][j][l] + max(0LL, h[i] - h[i - 1 - l]));
      }
      for (int l = 1; l <= j; ++l) {
        chmin(dp[i][j][l], dp[i - 1][j - 1][l - 1]);
      }
    }
  }

  long long res = INF;
  for (auto r : dp[n][k]) chmin(res, r);
  cout << res << endl;
  return 0;
}
