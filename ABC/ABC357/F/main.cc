#include <iostream>
#include <vector>
//
#include <atcoder/lazysegtree>
#include <atcoder/modint>

using namespace std;
using ll = long long;
// clang-format off
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) { ll in; is >> in; m = in; return is; }
ostream &operator<<(ostream &os, const mint &m) { os << m.val(); return os; }
// clang-format on

struct S {
  mint a, b, c;
  int siz;
};

struct F {
  mint a, b;
};

S Op(S x, S y) { return {x.a + y.a, x.b + y.b, x.c + y.c, x.siz + y.siz}; }
S E() { return {0, 0, 0, 0}; }
S Map(F f, S x) {
  return {x.a + f.a * x.siz, x.b + f.b * x.siz,
          x.c + f.a * x.b + f.b * x.a + f.a * f.b * x.siz, x.siz};
}
F Composite(F f, F g) { return {f.a + g.a, f.b + g.b}; }
F Id() { return {0, 0}; }
using LazySegtree = atcoder::lazy_segtree<S, Op, E, F, Map, Composite, Id>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<mint> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  LazySegtree seg(n);
  for (int i = 0; i < n; ++i) {
    seg.set(i, {a[i], b[i], a[i] * b[i], 1});
  }

  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    if (t == 1) {
      mint x;
      cin >> x;
      seg.apply(l, r, {x, 0});
    } else if (t == 2) {
      mint x;
      cin >> x;
      seg.apply(l, r, {0, x});
    } else {
      cout << seg.prod(l, r).c << endl;
    }
  }

  return 0;
}