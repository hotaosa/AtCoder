#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<vector<mint> > > dp(n + 1, vector<vector<mint> > (6001, vector<mint>(3, 0)));
  dp[0][0][0] = 1;

  for (int pos = 0; pos < n; ++pos) {
    for (int sum = 0; sum <= s; ++sum) {
      for (int st = 0; st < 3; ++st) {
        for (int nx = st; nx < 3; ++nx) {
          dp[pos + 1][sum][nx] += dp[pos][sum][st];
          if (nx > 0 && st < 2) dp[pos + 1][sum + a[pos]][nx] += dp[pos][sum][st];
        }
      }
    }
  }

  cout << dp[n][s][2].val() << endl;  
  return 0;
}
