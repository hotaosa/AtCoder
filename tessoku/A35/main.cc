#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > dp(n, vector<int>(n));
  for (int i = 0; i < n; ++i) cin >> dp[n - 1][i];

  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      if (i & 1) dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
      else dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }

  cout << dp[0][0] << endl;  
  return 0;
}
