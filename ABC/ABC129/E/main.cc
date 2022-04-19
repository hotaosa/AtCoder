#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  vector<vector<mint> > dp(n, vector<mint>(2, 0));
  dp[0][1] = 1;
  dp[0][0] = 2;

  for (int i = 1; i < n; ++i) {
    if (s[i] == '1') {
      dp[i][1] = dp[i - 1][1] * 3 + dp[i - 1][0];
      dp[i][0] = dp[i - 1][0] * 2;
    } else {
      dp[i][1] = dp[i - 1][1] * 3;
      dp[i][0] = dp[i - 1][0];
    }
  }

  mint res = dp[n - 1][0] + dp[n - 1][1];
  cout << res.val() << endl;
  return 0;
}
