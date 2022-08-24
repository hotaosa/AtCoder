#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<long long> v(n);
  for (auto &p : v) cin >> p;

  vector<vector<pair<long long, long long> > > dp(n + 1, vector<pair<long long, long long> >(n + 1, {0, 0}));
  dp[0][0] = {0, 1};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j].first == dp[i + 1][j].first) dp[i + 1][j].second += dp[i][j].second;
      else if (dp[i][j].first > dp[i + 1][j].first) dp[i + 1][j] = dp[i][j];
      if (dp[i][j].first + v[i] == dp[i + 1][j + 1].first) dp[i + 1][j + 1].second += dp[i][j].second;
      else if (dp[i][j].first + v[i] > dp[i + 1][j + 1].first) dp[i + 1][j + 1] = {dp[i][j].first + v[i], dp[i][j].second};
    }
  }

  long long d = a, m = dp[n][a].first;
  long long cnt = dp[n][a].second;

  for (int i = a + 1; i <= b; ++i) {
    if (m * i == dp[n][i].first * d) cnt += dp[n][i].second;
  }

  printf("%.10f\n%lld\n", double(m) / d, cnt);
  return 0;
}
