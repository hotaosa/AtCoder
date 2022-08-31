#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

long long op(long long a, long long b) {
  return a + b;
}
long long e() {
  return 0;
}

using segtree = atcoder::segtree<long long, op, e>;

int main() {
  int n, q;
  cin >> n >> q;

  segtree seg_odd(n), seg_even(n);
  atcoder::dsu uf(n);

  while (q--) {
    int t, x, y;
    long long v;
    cin >> t >> x >> y >> v;
    --x; --y;
    if (t == 0) {
      if (y & 1) seg_odd.set(y, v);
      else seg_even.set(y, v);
      uf.merge(x, y);
    }
    if (t == 1) {
      if (!uf.same(x, y)) {
        cout << "Ambiguous" << endl;
        continue;
      }
      long long sum = 0;
      int l = min(x, y) + 1;
      int r = max(x, y) + 1;
      if (x < y) {
        if (y & 1) {
          sum = seg_odd.prod(l, r) - seg_even.prod(l, r);
        } else {
          sum = seg_even.prod(l, r) - seg_odd.prod(l, r);
        }
      } else {
        if (y & 1) {
          sum = seg_even.prod(l, r) - seg_odd.prod(l, r);
        } else {
          sum = seg_odd.prod(l, r) - seg_even.prod(l, r);
        }
      }
      cout << sum + v * ((x ^ y) & 1 ? -1 : 1) << endl;
    }
  }
  return 0;
}
