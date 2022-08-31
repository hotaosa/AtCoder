#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<long long> > dp(d + 1, vector<long long>(1 << n, 0));
  dp[0][0] = 1;

  vector<int> add(d, 0);
  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j] & (1LL << i)) add[i] |= (1 << j);
    }
  }

  for (int i = 0; i < d; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      dp[i + 1][j] += dp[i][j];
      dp[i + 1][j | add[i]] += dp[i][j];
    }
  }

  cout << dp[d][(1 << n) - 1] << endl;  
  return 0;
}
