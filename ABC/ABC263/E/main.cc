#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;
  vector<int> a(n - 1);  
  for (auto &p : a) cin >> p;

  vector<mint> dp(n, 0), sum(n + 2, 0);
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = mint(a[i]).inv() * (sum[i + 1] - sum[i + a[i] + 1] + 1 + a[i]);
    sum[i] = sum[i + 1] + dp[i];
  }

  cout << dp[0].val() << endl;  
  return 0;
}
