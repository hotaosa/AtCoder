#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<mint> > dp(n + 1, vector<mint>(k + 1, 0));
  dp[0][0] = 1;
  
  for (int pos = 0; pos < n; ++pos) {
    for (int sum = 0; sum < k; ++sum) {
      for (int cur = 1; cur <= m && sum + cur <= k; ++cur) {
        dp[pos + 1][sum + cur] += dp[pos][sum];
      }
    }
  }

  mint res = 0;
  for (auto p : dp[n]) res += p;
  cout << res.val() << endl;
  return 0;
}
