#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int l, int r) { return max(l, r); }
int e() { return 0; }
int mapping(int f, int x) { return max(f, x); }
int composition(int f, int g) { return max(f, g); }
int id() { return 0; }

using lazy_segtree = atcoder::lazy_segtree<int, op, e, int, mapping, composition, id>;

int main() {
  int w, n;
  cin >> w >> n;

  lazy_segtree seg(w + 1);

  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    int h = seg.prod(--l, r) + 1;
    cout << h << endl;
    seg.apply(l, r, h);
  }
  return 0;
}
