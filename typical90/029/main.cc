#include <iostream>
#include <vector>

template <typename T> struct RangeMax {
  int n;
  std::vector<T> dat, lazy;
  RangeMax(int n_) : n(), dat(n_ * 4, 0), lazy(n_ * 4, 0) {
    int x = 1;
    while (x < n_) x *= 2;
    n = x;
  }

  void eval(int k) {
    if (lazy[k] == 0) return;
    if (k < n - 1) {
      lazy[k * 2 + 1] = lazy[k];
      lazy[k * 2 + 2] = lazy[k];
    }
    dat[k] = lazy[k];
    lazy[k] = 0;
  }

  void update(int a, int b, T x, int k, int l, int r) {
    eval(k);
    if (a <= l && b >= r) {
      lazy[k] = x;
      eval(k);
    } else if (a < r && l < b) {
      update(a, b, x, k * 2 + 1, l, (l + r) / 2);
      update(a, b, x, k * 2 + 2, (l + r) / 2, r);
      dat[k] = std::max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, T x) { update(a, b, x, 0, 0, n); }

  T query(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) return 0;
    else if (a <= l && r <= b) return dat[k];
    else {
      T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return std::max(vl, vr);
    }
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  int w, n;
  std::cin >> w >> n;
  RangeMax<int> seg(w);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    int res = seg.query(--l, r) + 1;
    std::cout << res << std::endl;
    seg.update(l, r, res);    
  }
  return 0;
}
