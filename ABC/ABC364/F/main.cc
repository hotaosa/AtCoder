#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/lazysegtree>

using namespace std;
using ll = long long;

struct S {
  int value;
  int size;
};
using F = int;
S Operate(S a, S b) { return {a.value + b.value, a.size + b.size}; }
S E() { return {0, 0}; }
F Id() { return -1; }
S Map(F f, S a) { return f == Id() ? a : S{f * a.size, a.size}; }
F Composite(F f, F g) { return f == Id() ? g : f; }
using LazySegtree = atcoder::lazy_segtree<S, Operate, E, F, Map, Composite, Id>;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> l(q), r(q);
  vector<ll> c(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i] >> c[i];
    --l[i];
    --r[i];
  }

  vector<int> o(q);
  iota(begin(o), end(o), 0);
  sort(begin(o), end(o), [&c](int i, int j) { return c[i] < c[j]; });

  LazySegtree seg(vector<S>(n - 1, {1, 1}));
  ll res = accumulate(begin(c), end(c), 0LL);

  for (int i : o) {
    res += c[i] * seg.prod(l[i], r[i]).value;
    seg.apply(l[i], r[i], 0);
  }

  if (seg.all_prod().value > 0) res = -1;
  cout << res << endl;
  return 0;
}