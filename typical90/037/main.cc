#include <iostream>
#include <vector>

constexpr long long INF = 1LL << 60;

struct SegTree {
  int n = 1;
  std::vector<long long> dat;
  SegTree(int n_) : dat(n_ * 4, -INF) { while (n < n_) n *= 2; }
  void update(int i, long long x) {
    i += n - 1;
    dat[i] = std::max(dat[i], x);
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = std::max(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  long long query(int a) { return query(a, a + 1, 0, 0, n); }
  long long query(int a, int b) { return query(a, b, 0, 0, n); }
  long long query(int a, int b, int k, int l, int r) {
    if (a >= r || b <= l) return -INF;
    else if (a <= l && b >= r) return dat[k];
    else {
      long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return std::max(vl, vr);
    }
  }
};

int main() {
  int w, n;
  std::cin >> w >> n;
  std::vector<SegTree> dp;
  dp.push_back(SegTree(w + 1));
  dp[0].update(0, 0);
  for (int i = 0; i < n; ++i) {
    dp.push_back(dp.back());
    int l, r;
    long long v;
    std::cin >> l >> r >> v;
    for (int j = l; j <= w; ++j) {
      dp[i + 1].update(j, dp[i].query(std::max(j - r, 0), j - l + 1) + v);
    }
  }

  std::cout << std::max(-1LL, dp.back().query(w)) << std::endl;
  return 0;
}
