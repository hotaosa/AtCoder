#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}
template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  long long x;
  cin >> n >> x;

  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  long long res = INF;
  for (int count = 1; count <= n; ++count) {
    vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> > (count + 1, vector<long long>(count, -1)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= count; ++j) {
        for (int k = 0; k < count; ++k) {
          if (dp[i][j][k] == -1) continue;
          chmax(dp[i + 1][j][k], dp[i][j][k]);
          if (j < count) chmax(dp[i + 1][j + 1][(k + a[i]) % count], dp[i][j][k] + a[i]);
        }
      }
    }
    if (dp[n][count][x % count] > 0) chmin(res, (x - dp[n][count][x % count]) / count);
  }

  cout << res << endl;
  return 0;  
}
