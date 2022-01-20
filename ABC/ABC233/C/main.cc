#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long x;
  cin >> n >> x;
  vector<vector<long long> > a(n);
  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;
    a[i].resize(l);
    for (int j = 0; j < l; ++j) cin >> a[i][j];
  }
  vector<map<long long, long long> > dp(n + 1);
  dp[0][1] = 1;
  for (int i = 0; i < n; ++i) {
    for (auto m : dp[i]) {
      for (long long nx : a[i]) {
        if (m.first > (x + nx - 1) / nx) continue;
        dp[i + 1][m.first * nx] += m.second;
      }
    }
  }

  cout << dp[n][x] << endl;
  return 0;
}
