#include <iomanip>
#include <iostream>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ld = long double;

ld Op(ld a, ld b) { return a + b; }
ld E() { return 0.0L; }
using Segtree = atcoder::segtree<ld, Op, E>;

int main() {
  cout << fixed << setprecision(10);
  int n, l, d;
  cin >> n >> l >> d;

  ld d_inv = 1.0L / d;
  Segtree seg1(n + 1);
  seg1.set(0, 1.0);
  for (int y = 1; y <= n; ++y) {
    int left = max(0, y - d);
    int right = min(y, l);
    if (right > left) {
      seg1.set(y, seg1.prod(left, right) * d_inv);
    }
  }
  for (int y = 0; y < l; ++y) {
    seg1.set(y, 0.0L);
  }
  ld p_over = 1.0 - seg1.all_prod();

  Segtree seg2(n + 1);
  for (int x = n; x >= 0; --x) {
    seg2.set(x, max(p_over + seg1.prod(0, x),
                    seg2.prod(x + 1, min(x + d + 1, n + 1)) * d_inv));
  }

  cout << seg2.get(0) << endl;
  return 0;
}
