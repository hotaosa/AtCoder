#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  vector dp(2, vector<int>(n, 0));
  dp[0][0] = dp[1][n - 1] = 1;
  for (int i = 1; i < n; ++i) dp[0][i] = min(dp[0][i - 1] + 1, a[i]);
  for (int i = n - 1; i >= 0; --i) dp[1][i] = min(dp[1][i + 1] +1, a[i]);

  int res = 0;
  for (int i = 0; i < n; ++i) res = max(res, min(dp[0][i], dp[1][i]));
  cout << res << endl;

  return 0;
}