#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, p;
  cin >> n >> p;

  mint prob = p / mint(100);
  mint prob_rev = 1 - prob;

  vector<mint> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; ++i) {
    dp[i] = prob * dp[i - 2] + prob_rev * dp[i - 1] + 1;
  }

  cout << dp[n].val() << endl;  
  return 0;
}
