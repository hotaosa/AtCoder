#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (101, vector<int>(101, 0)));
  for (int i = 0; i < n; ++i) {
    for (int ph = 0; ph <= 100; ++ph) {
      for (int sp = 0; sp <= 100; ++sp) {
        dp[i + 1][ph][sp] = dp[i][ph][sp];
        if (a[i] < ph || a[i] > ph + k) continue;
        if (b[i] < sp || b[i] > sp + k) continue;
        ++dp[i + 1][ph][sp];
      }
    }
  }

  int res = 0;
  for (int ph = 0; ph <= 100; ++ph) for (int sp = 0; sp <= 100; ++sp) res = max(res, dp[n][ph][sp]);
  cout << res << endl;  
  return 0;
}
