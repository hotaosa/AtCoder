#include <iostream>
//
#include <atcoder/segtree>

using namespace std;

int op(int a, int b) { return a + b; }
int e() { return 0; }
using Segtree = atcoder::segtree<int, op, e>;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;

  Segtree seg(n);
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      seg.set(i, 1);
    }
  }

  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      if (--l > 0) {
        seg.set(l, seg.get(l) ^ 1);
      }
      if (--r < n - 1) {
        seg.set(r + 1, seg.get(r + 1) ^ 1);
      }
    } else {
      cout << (seg.prod(l, r) ? "No\n" : "Yes\n");
    }
  }

  return 0;
}
