#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;
constexpr int SIZE = 100001;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, long long> > sunuke(SIZE, {0, 0});
  for (int i = 0; i < n; ++i) {
    int t, x;
    long long a;
    cin >> t >> x >> a;
    sunuke[t] = {x, a};
  }

  vector<vector<long long> > dp(SIZE, vector<long long>(5, -INF));
  dp[0][0] = 0;

  for (int i = 1; i < SIZE; ++i) {
    for (int j = 0; j < 5; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j > 0) chmax(dp[i][j], dp[i - 1][j - 1]);
      if (j < 4) chmax(dp[i][j], dp[i - 1][j + 1]);
      if (sunuke[i].first == j) dp[i][j] += sunuke[i].second;
    }
  }

  long long res = 0;
  for (auto r : dp.back()) chmax(res, r);
  cout << res << endl;
  return 0;
}
