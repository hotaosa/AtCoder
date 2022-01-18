#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a == 0 || a > b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<map<long long, long long> > dp(n + 1);
  dp[n][x] = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (auto m : dp[i + 1]) {      
      chmin(dp[i][m.first % a[i]], m.second + m.first / a[i]);
      chmin(dp[i][a[i] - (m.first % a[i])], m.second + m.first / a[i] + 1);
    }
    dp[i][x] = 0;
  }
  cout << dp[0][0] << endl;
  return 0;
}
