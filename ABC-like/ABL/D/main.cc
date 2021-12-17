#include <bits/stdc++.h>
#include <atcoder/all>

int op(int a, int b) {
  return std::max(a, b);
}

int e() {
  return 0;
}

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    int ma = 0;
    for (auto &p : a) { std::cin >> p; chmax(ma, p); }

    atcoder::segtree<int, op, e> seg(ma + 1);
    for (int i = 0; i < n; ++i) {
        int left = std::max(0, a[i] - k);
        int right = std::min(ma, a[i] + k) + 1;
        seg.set(a[i], seg.prod(left, right) + 1);
    }

    std::cout << seg.all_prod() << std::endl;
    return 0;
}
