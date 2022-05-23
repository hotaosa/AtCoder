#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using S = int;
using F = int;

int n, q;
S op(S l, S r) { return min(l, r); }
S e() { return n - 1; }
S mapping(F f, S x) { return min(f, x); }
F composition(F f, F g) { return min(f, g); }
F id() { return n - 1; }

int main() {  
  cin >> n >> q;

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg_r(n), seg_c(n);  

  long long res = (long long)(n - 2) * (n - 2);
  while (q--) {
    int t, x;
    cin >> t >> x;
    --x;
    if (t == 1) {    
      int p = seg_r.get(x);
      res -= p - 1;
      seg_c.apply(1, p, x);
    } else {
      int p = seg_c.get(x);
      res -= p - 1;
      seg_r.apply(1, p, x);
    }
  }
  cout << res << endl;
  return 0;
}
