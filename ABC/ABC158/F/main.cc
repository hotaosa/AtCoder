#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}

using segtree = atcoder::segtree<int, op, e>;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i].first >> vp[i].second;
    vp[i].second += vp[i].first;
  }
  sort(vp.begin(), vp.end());
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) tie(l[i], r[i]) = vp[i];  

  segtree seg(n);
  for (int i = 0; i < n; ++i) seg.set(i, i + 1);

  vector<mint> dp(n + 1);
  dp[n] = 1;

  for (int i = n - 1; i >= 0; --i) {
    int j = lower_bound(l.begin(), l.end(), r[i]) - l.begin();
    int nx = seg.prod(i, j);
    seg.set(i, nx);
    dp[i] = dp[i + 1] + dp[nx];
  }

  cout << dp[0].val() << endl;
  return 0;
}
