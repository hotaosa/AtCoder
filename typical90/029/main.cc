#include <iostream>
#include <vector>

struct RMQ {
  int n;
  std::vector<int> dat, lazy;
  RMQ(int n_) : n(), dat(n_ * 4, 0), lazy(n_ * 4, 0) {
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

  void update(int a, int b, int x, int k, int l, int r) {
    eval(k);
    if (a <= l && r <= b) {
      lazy[k] = x;
      eval(k);
    } else if (a < r && l < b) {
      update(a, b, x, k * 2 + 1, l, (l + r) / 2);
      update(a, b, x, k * 2 + 2, (l + r) / 2, r);
      dat[k] = std::max(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, int x) { update(a, b, x, 0, 0, n); }

  int query(int a, int b, int k, int l, int r) {
    eval(k);
    if (r <= a || b <= l) return 0;
    else if (a <= l && r <= b) return dat[k];
    else {
      int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return std::max(vl, vr);
    }
  }
  int query(int a, int b) { return query(a, b, 0, 0, n); }
};

int main() {
  int w, n;
  std::cin >> w >> n;
  RMQ rmq(w + 1);
  std::vector<int> res;
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    ++r;
    int height = rmq.query(l, r);
    ++height;
    res.push_back(height);
    rmq.update(l, r, height);
  }

  for (int i = 0; i < n; ++i) std::cout << res[i] << std::endl;
  return 0;
}
