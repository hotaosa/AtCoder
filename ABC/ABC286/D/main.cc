#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    while (b--) v.push_back(a);
  }

  n = v.size();
  vector dp(n + 1, vector<bool>(x + 1, false));
  dp[0][0] = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= x; ++j) {
      if (!dp[i][j]) continue;
      dp[i + 1][j] = true;
      if (j + v[i] <= x) dp[i + 1][j + v[i]] = true;
    }
  }

  cout << (dp[n][x] ? "Yes" : "No" ) << endl;  
  return 0;
}
