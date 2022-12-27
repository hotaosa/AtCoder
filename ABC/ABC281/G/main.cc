#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int main() {
  int n;
  long long m;
  cin >> n >> m;
  mint::set_mod(m);  

  vector<vector<mint> > binom(n, vector<mint>(n, 0));
  binom[0][0] = 1;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j <= i; ++j) {
      binom[i + 1][j] += binom[i][j];
      binom[i + 1][j + 1] += binom[i][j];
    }
  }

  vector<mint> pow2(n * n);
  pow2[0] = 1;
  for (int i = 1; i < n * n; ++i) pow2[i] = pow2[i - 1] * 2;

  vector<vector<mint> > dp(n, vector<mint>(n, 0));
  dp[1][1] = 1;

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (dp[i][j] == 0) continue;
      for (int k = 1; i + k < n; ++k) {
        dp[i + k][k] += dp[i][j] * binom[n - 1 - i][k] * (pow2[j] - 1).pow(k) * pow2[k * (k - 1) / 2];
      }
    }
  }

  mint res = 0;
  for (int i = 1; i < n; ++i) {
    res += dp[n - 1][i] * (pow2[i] - 1);
  }

  cout << res.val() << endl;  
  return 0;
}
