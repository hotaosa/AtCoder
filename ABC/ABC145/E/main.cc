#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, t;
  cin >> n >> t;
  vector<pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) cin >> vp[i].first >> vp[i].second;
  sort(vp.begin(), vp.end());

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[i] = vp[i].first;
    b[i] = vp[i].second;
  }

  vector<vector<int> > dp(n + 1, vector<int>(t + 3000, 0)), dm(n + 1, vector<int>(t + 3000, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < t + 3000; ++j) {
      dp[i][j] = dm[i - 1][j];
      if (j >= a[i - 1] && j - a[i - 1] < t) chmax(dp[i][j], dp[i - 1][j - a[i - 1]] + b[i - 1]);
      dm[i][j] = dp[i][j];
      if (j > 0) chmax(dm[i][j], dm[i][j - 1]);
    }
  }
  cout << dm.back().back() << endl;
  return 0;
}