#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, w;
  cin >> n >> w;
  vector<long long> weight(n), value(n);
  for (int i = 0; i < n; ++i) cin >> weight[i] >> value[i];

  vector<vector<long long> > dp(n + 1, vector<long long>(w + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= w; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + weight[i] <= w) chmax(dp[i + 1][j + weight[i]], dp[i][j] + value[i]);
    }
  }

  long long res = 0;
  for (auto d : dp.back()) chmax(res, d);
  cout << res << endl;  
  return 0;
}
