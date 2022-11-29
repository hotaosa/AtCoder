#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;

  int mx = 0;
  vector<int> a(n);
  for (auto &p : a) {
    cin >> p;
    mx = max(mx, p);
  }

  vector<mint> dp(n);
  dp[0] = a[0];

  atcoder::fenwick_tree<mint> ft_cnt(mx + 1), ft_sum(mx + 1);  
  ft_cnt.add(a[0], 1);
  ft_sum.add(a[0], a[0]);

  for (int i = 1; i < n; ++i) {    
    mint p = mint(i + 1).inv();
    dp[i] = dp[i - 1] * (1 - p) * (1 - p);
    dp[i] += 2 * (ft_cnt.sum(0, a[i]) * a[i] + ft_sum.sum(a[i], mx + 1)) * p * (1 - p) / i;
    dp[i] += a[i] * p * p;
    ft_cnt.add(a[i], 1);
    ft_sum.add(a[i], a[i]);
  }

  for (auto d : dp) cout << d.val() << endl;  
  return 0;
}
