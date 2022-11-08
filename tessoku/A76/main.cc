#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, w, l, r;
  cin >> n >> w >> l >> r;
  n += 2;
  vector<int> x(n, 0);
  for (int i = 1; i < n - 1; ++i) cin >> x[i];
  x[n - 1] = w;

  vector<mint> dp(n, 0), ds(n, 0);
  dp[0] = ds[0] = 1;

  for (int i = 1; i < n; ++i) {
    ds[i] = ds[i - 1];
    auto id_l = lower_bound(x.begin(), x.end(), x[i] - r) - x.begin();
    auto id_r = upper_bound(x.begin(), x.end(), x[i] - l) - x.begin();
    if (id_r == 0) continue;
    dp[i] = ds[id_r - 1];
    if (id_l > 0) dp[i] -= ds[id_l - 1];
    ds[i] += dp[i];
  }

  cout << dp.back().val() << endl;
  return 0;
}
