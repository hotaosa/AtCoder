#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  long long k;
  cin >> n >> k;
  if (k == 1) { cout << "1 1 1" << endl; return 0; }
  if ((long long)n * n * n == k) { cout << n << " " << n << " " << n << endl; return 0; }

  vector<vector<long long> > dp(4, vector<long long>(n * 3 + 2, 0));
  dp[0][0] = 1;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j <= i * n; ++j) {
      dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j + n + 1] -= dp[i][j];
    }
    for (int j = 1; j <= n * 3; ++j) dp[i + 1][j] += dp[i + 1][j - 1];
  }
  for (int i = 1; i <= n * 3; ++i) dp[3][i] += dp[3][i - 1];

  int sum = lower_bound(dp[3].begin(), dp[3].end(), k) - dp[3].begin();
  k -= dp[3][sum - 1];

  for (int b = 1; b <= n; ++b) {
    int x = min(n, sum - b - 1);
    int y = max(1, sum - b - n);
    if (x - y + 1 <= 0) continue;
    if (x - y + 1 < k) k -= x - y + 1;
    else {
      int d = y + k - 1;
      int p = sum - b - d;
      cout << b << " " << d << " " << p << endl;
      return 0;
    }
  }    
  return 0;
}
