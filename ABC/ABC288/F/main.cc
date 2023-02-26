#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  string x;
  cin >> n >> x;

  vector<mint> dp(n + 1, 0), ds(n + 1, 1);
  for (int i = 0; i < n; ++i) {
    int c = x[i] - '0';
    dp[i + 1] = dp[i] * 10 + ds[i] * c;
    ds[i + 1] = ds[i] + dp[i + 1];
  }

  cout << dp.back().val() << endl;
  return 0;
}
