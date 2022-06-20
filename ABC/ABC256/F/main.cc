#include <iostream>
#include <vector>
#include <atcoder/modint>
#include <atcoder/fenwicktree>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, q;
  cin >> n >> q;

  atcoder::fenwick_tree<mint> bit0(n + 1), bit1(n + 1), bit2(n + 1);

  auto update = [&](atcoder::fenwick_tree<mint> &bit, int p, mint v) -> void {
    mint cur = bit.sum(p, p + 1);
    bit.add(p, v - cur);
  };

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mint ai = a;
    bit0.add(i, ai);
    bit1.add(i, ai * i);
    bit2.add(i, ai * i * i);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      long long v;
      cin >> x >> v;
      --x;
      update(bit0, x, mint(v));
      update(bit1, x, mint(v) * mint(x));
      update(bit2, x, mint(v) * mint(x) * mint(x));
    } else {
      int x;
      cin >> x;
      mint res = bit2.sum(0, x);
      res -= (mint(x) * mint(2) + mint(1)) * bit1.sum(0, x);
      res += (mint(x) * mint(x) + mint(x)) * bit0.sum(0, x);
      res /= 2;
      cout << res.val() << endl;
    }
  }
  return 0;
}
