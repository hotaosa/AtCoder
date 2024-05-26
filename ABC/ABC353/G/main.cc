#include <iostream>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

ll Operate(ll a, ll b) { return max(a, b); }
ll E() { return -INF; }
using SegTree = atcoder::segtree<ll, Operate, E>;

int main() {
  int n, m;
  ll c;
  cin >> n >> c >> m;

  SegTree seg_l(n), seg_r(n);
  for (int i = 0; i < n; ++i) {
    seg_l.set(i, 0);
    seg_r.set(i, -c * i * 2);
  }

  ll res = 0;
  while (m--) {
    int t;
    ll p;
    cin >> t >> p;
    --t;
    auto cur = p + max(seg_l.prod(0, t) - c * t, seg_r.prod(t, n) + c * t);
    res = max(res, cur);
    seg_l.set(t, cur + c * t);
    seg_r.set(t, cur - c * t);
  }

  cout << res << endl;
  return 0;
}