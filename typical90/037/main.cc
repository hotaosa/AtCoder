#include <iostream>
#include <vector>

const long long INF = 1LL << 60;

struct RangeMax {
  int size = 1;
  std::vector<long long> dat;
  RangeMax(int size_) {
    while (size <= size_) size *= 2;
    dat.resize(size * 2, -INF);
  }
  void update(int pos, long long x) {
    pos += size;
    dat[pos] = x;
    while (pos >= 2) {
      pos >>= 1;
      dat[pos] = std::max(dat[pos * 2], dat[pos * 2 + 1]);
    }
  }
  long long query(int l, int r, int a, int b, int u) {
    if (l <= a && b <= r) return dat[u];
    if (r <= a || b <= l) return -INF;
    long long v1 = query(l, r, a, (a + b) / 2, u * 2);
    long long v2 = query(l, r, (a + b) / 2, b, u * 2 + 1);
    return std::max(v1, v2);
  }
  long long query(int l, int r) { return query(l, r, 0, size, 1); }
};

int main() {
  int w, n;
  std::cin >> w >> n;
  std::vector<int> l(n + 1), r(n + 1);
  std::vector<long long> v(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> l[i] >> r[i] >> v[i];

  RangeMax rm(w + 2);
  std::vector<std::vector<long long> > dp;
  dp.push_back(std::vector<long long>(w + 2, -INF));
  dp[0][0] = 0;
  rm.update(0, 0);

  for (int i = 1; i <= n; ++i) {
    dp.push_back(dp.back());
    for (int j = 0; j <= w; ++j) {
      int cl = std::max(0, j - r[i]);
      int cr = std::max(0, j - l[i] + 1);
      long long val = rm.query(cl, cr);
      if (val > -1LL) dp[i][j] = std::max(dp[i][j], val + v[i]);
    }
    for (int j = 0; j <= w; ++j) rm.update(j, dp[i][j]);
  }

  std::cout << std::max(-1LL, dp[n][w]) << std::endl;
  return 0;
}
