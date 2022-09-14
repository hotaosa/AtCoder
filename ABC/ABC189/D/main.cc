#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (auto &p : vs) cin >> p;

  vector<vector<long long> > dp(n + 1, vector<long long>(2, 0));
  dp[0][0] = dp[0][1] = 1;

  for (int i = 0; i < n; ++i) {
    if (vs[i] == "AND") {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i + 1][j & k] += dp[i][j];
        }
      }
    } else {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          dp[i + 1][j | k] += dp[i][j];
        }
      }
    }
  }

  cout << dp[n][1] << endl;  
  return 0;
}
