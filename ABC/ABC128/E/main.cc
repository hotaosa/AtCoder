#include <iostream>
#include <vector>
#include <atcoder/lazysegtree>

using namespace std;
using S = int;
using F = int;

constexpr int INF = 1 << 30;

S op(S l, S r) { return min(l, r); }
S e() { return INF; }
S mapping(F f, S x) { return min(f, x); }
F composition(F f, F g) { return min(f, g); }
F id() { return INF; }

using lazy_segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> s(n), t(n), x(n);
  for (int i = 0; i < n; ++i) cin >> s[i] >> t[i] >> x[i];
  vector<int> d(q);
  for (int i = 0; i < q; ++i) cin >> d[i];

  lazy_segtree seg(q + 1);
  for (int i = 0; i < n; ++i) {
    int ps = lower_bound(d.begin(), d.end(), s[i] - x[i]) - d.begin();
    int pt = lower_bound(d.begin(), d.end(), t[i] - x[i]) - d.begin();
    seg.apply(ps, pt, x[i]);
  }
  for (int i = 0; i < q; ++i) {
    int res = seg.get(i);
    cout << (res < INF ? res : -1) << endl;
  }
  return 0;
}