#include <iostream>
#include <vector>

constexpr int INF = 1 << 30;

struct LazySegmentTree {
  int n;
  std::vector<int> dat, lazy;
  LazySegmentTree(int n_) : n(1), dat(n_ * 4, 0), lazy(n_ * 4, 0) { while (n < n_) n *= 2; }
  void eval(int k) {
    if (lazy[k] == 0) return;
    if (k < n - 1) {
      lazy[k * 2 + 1] += lazy[k];
      lazy[k * 2 + 2] += lazy[k];
    }
    dat[k] += lazy[k];
    lazy[k] = 0;
  }
  void update(int a, int b, int x, int k, int l, int r) {
    eval(k);
    if (a <= l && b >= r) {
      lazy[k] += x;
      eval(k);
    } else if (a < r && l < b) {
      update(a, b, x, k * 2 + 1, l, (l + r) / 2);
      update(a, b, x, k * 2 + 2, (l + r) / 2, r);
      dat[k] = std::min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, int x) { update(a, b, x, 0, 0, n); }
  void update(int a, int x) { update(a, a + 1, x, 0, 0, n); }
  int query(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) return INF;
    else if (a <= l && r <= b) return dat[k];
    else {
      int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return std::min(vl, vr);
    }
  }
  int query(int a, int b) { return query(a, b, 0, 0, n); }
  int query(int a) { return query(a, a + 1, 0, 0, n); }
};

int main() {
  int n, q;
  std::string s = "a";
  std::string ss;
  std::cin >> n >> q >> ss;
  s += ss;

  LazySegmentTree seg(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += (s[i] == '(' ? 1 : -1);
    seg.update(i, sum);
  }

  while (q--) {
    int t, l, r;
    std::cin >> t >> l >> r;
    if (t == 1) {
      if (s[l] != s[r]) {
        int d = (s[l] == '(' ? -2 : 2);
        seg.update(l, r, d);
        std::swap(s[l], s[r]);
      }
    } else {
      bool rp = (seg.query(r) == seg.query(l - 1));
      rp &= (seg.query(l, r + 1) == seg.query(r));
      std::cout << (rp ? "Yes" : "No") << std::endl;
    }
  }
  return 0;
}
