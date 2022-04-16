#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

using S = int;
using F = int;

S op(S l, S r) { return max(l, r); }
S e() { return 0; }
S mapping(F f, S x) { return max(f, x); }
F composition(F f, F g) { return max(f, g); }
F id() { return 0; }

int main() {
  int w, n;
  cin >> w >> n;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(w + 1);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    int res = seg.prod(l, r + 1) + 1;
    cout << res << endl;
    seg.apply(l, r + 1, res);
  }
  return 0;
}
