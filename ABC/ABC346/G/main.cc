#include <iostream>
//
#include <atcoder/lazysegtree>

using namespace std;
using ll = long long;

struct S {
  int val;
  ll cnt;
};
S Operate(S a, S b) {
  if (a.val > b.val) {
    return b;
  }
  if (a.val == b.val) {
    a.cnt += b.cnt;
  }
  return a;
}
S E() { return S{1 << 30, 0}; }
S Mapping(int f, S x) {
  x.val += f;
  return x;
}
int Composition(int f, int g) { return f + g; }
int Id() { return 0; }
using LazySegtree =
    atcoder::lazy_segtree<S, Operate, E, int, Mapping, Composition, Id>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
    e--;
  }

  vector prv(n, vector<int>(2, n));
  LazySegtree seg(vector<S>(n, S{0, 1}));
  ll res = 0;
  for (int l = n - 1; l >= 0; --l) {
    seg.apply(prv[a[l]][0], prv[a[l]][1], -1);
    seg.apply(l, prv[a[l]][0], 1);
    prv[a[l]][1] = prv[a[l]][0];
    prv[a[l]][0] = l;
    res += n;
    auto s = seg.all_prod();
    if (s.val == 0) res -= s.cnt;
  }

  cout << res << endl;
  return 0;
}