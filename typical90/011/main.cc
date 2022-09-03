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
  vector<int> d(n), c(n);
  vector<long long> s(n);
  for (int i = 0; i < n; ++i) cin >> d[i] >> c[i] >> s[i];

  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) {
    return d[i] < d[j];
  });

  vector<vector<long long> > dp(n + 1, vector<long long>(5001, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5001; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + c[order[i]] <= d[order[i]]) chmax(dp[i + 1][j + c[order[i]]], dp[i][j] + s[order[i]]);
    }
  }

  long long res = 0;
  for (auto r : dp[n]) chmax(res, r);
  cout << res << endl;
  return 0;
}
