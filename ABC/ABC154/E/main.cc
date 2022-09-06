#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> >(2, vector<long long>(k + 1, 0)));
  dp[0][0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (s[i] == '0') {
        dp[i + 1][0][j] += dp[i][0][j];
        dp[i + 1][1][j] += dp[i][1][j];
      } else {
        dp[i + 1][1][j] += dp[i][0][j] + dp[i][1][j];
      }
      if (j == k) continue;
      for (int k = 1; k < 10; ++k) {
        if (k < (s[i] - '0')) {
          dp[i + 1][1][j + 1] += dp[i][1][j] + dp[i][0][j];
        } else if (k == (s[i] - '0')) {
          dp[i + 1][1][j + 1] += dp[i][1][j];
          dp[i + 1][0][j + 1] += dp[i][0][j];
        } else {
          dp[i + 1][1][j + 1] += dp[i][1][j];
        }
      }
    }
  }

  cout << dp[n][1][k] + dp[n][0][k] << endl;  
  return 0;
}
