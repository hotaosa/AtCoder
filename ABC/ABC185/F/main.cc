#include <bits/stdc++.h>
#include <atcoder/all>

int op(int a, int b) {
  return a ^ b;
}

int e() {
  return 0;
}

int main() {
    int n, q;
    std::cin >> n >> q;
    atcoder::segtree<int, op, e> seg(n);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        seg.set(i, a);
    }

    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if (t == 1) seg.set(x - 1, seg.get(x - 1) ^ y);
        else std::cout << seg.prod(x - 1, y) << std::endl;
    }
    return 0;
}
