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
  int mx = 0;
  vector<pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    int t, d;
    cin >> t >> d;
    mx = max(mx, d);
    vp.emplace_back(d, t);
  }
  sort(vp.begin(), vp.end());

  vector<vector<int> > dp(n + 1, vector<int>(mx + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= mx; ++j) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j + vp[i].second <= vp[i].first) chmax(dp[i + 1][j + vp[i].second], dp[i][j] + 1);
    }
  }

  int res = 0;
  for (int d : dp.back()) res = max(res, d);
  cout << res << endl;  
  return 0;
}
