#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int a, int b) {
  return a + b;
}
int e() {
  return 0;
}

using segtree = atcoder::segtree<int, op, e>;

int main() {
  int n, q;
  cin >> n >> q;
  segtree seg(n);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, x;
      cin >> p >> x;
      seg.set(--p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(--l, --r) << endl;
    }
  }
  
  return 0;
}
