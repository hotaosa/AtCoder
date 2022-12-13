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
  
  vector<pair<long long, int> > vp;
  for (int i = 0; i < n; ++i) {
    long long a;
    cin >> a;
    vp.emplace_back(a, i);
  }
  sort(vp.rbegin(), vp.rend());

  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 0));
  for (int i = 0; i < n; ++i) {
    auto [a, pos] = vp[i];
    for (int j = 0; j <= i; ++j) {
      chmax(dp[i + 1][j + 1], dp[i][j] + a * abs(j - pos));      
      chmax(dp[i + 1][j], dp[i][j] + a * abs(n - 1 - i + j - pos));
    }
  }

  long long res = 0;
  for (int i = 0; i <= n; ++i) chmax(res, dp[n][i]);
  cout << res << endl;
  return 0;
}
