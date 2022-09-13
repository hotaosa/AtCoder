#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int, int> > vp;
  for (int i = 1; i * i <= n; ++i) {
    vp.emplace_back(i, 0);
    vp.emplace_back(n / i, 0);
  }
  sort(vp.rbegin(), vp.rend());
  vp.erase(unique(vp.begin(), vp.end()), vp.end());

  int m = vp.size();
  for (int i = 0; i < m; ++i) {
    vp[i].second = n / vp[i].first - n / (vp[i].first + 1);
  }  

  vector<vector<mint> > dp(k + 1, vector<mint>(m, 0));
  dp[0].assign(m, 1);

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = dp[i - 1][m - 1 - j] * vp[j].second;
      if (j > 0) dp[i][j] += dp[i][j - 1];
    }
  }

  cout << dp[k][m - 1].val() << endl;
  return 0;
}
