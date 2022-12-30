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
  
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<long long> > dp(n + 1, vector<long long>(2, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      chmax(dp[i + 1][0], dp[i][j]);
      if (j == 0) chmax(dp[i + 1][1], dp[i][j] + a[i]);
    }
  }

  cout << max(dp[n][0], dp[n][1]) << endl;  
  return 0;
}
