#include <iostream>
#include <vector>

struct Point {
  long long x, y;
  Point(long long x_, long long y_) : x(x_), y(y_) { }
};

long long dist_sq(Point a, Point b) {
  long long dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

int main() {
  constexpr long long INF = 1LL << 60;
  
  int n, k;
  std::cin >> n >> k;
  std::vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    std::cin >> x >> y;
    vp.push_back(Point(x, y));
  }

  std::vector<long long> d((1 << n), 0LL);
  for (int bit = 1; bit < (1 << n); ++bit) {
    std::vector<int> ids;
    for (int i = 0; i < n; ++i) if (bit & (1 << i)) ids.push_back(i);
    if (ids.size() == 1) continue;
    for (int i = 0; i < (int)ids.size() - 1; ++i) {
      for (int j = i + 1; j < (int)ids.size(); ++j) {
        d[bit] = std::max(d[bit], dist_sq(vp[ids[i]], vp[ids[j]]));
      }
    }
  }

  std::vector<std::vector<long long> > dp((1 << n), std::vector<long long>(k + 1, INF));
  for (int bit = 1; bit < (1 << n); ++bit) {
    dp[bit][1] = d[bit];
    for (int i = 2; i <= k; ++i) {
      for (int bit1 = bit; bit1 > 0; bit1 = (bit1 - 1) & bit) {
        int bit2 = bit - bit1;
        dp[bit][i] = std::min(dp[bit][i], std::max(dp[bit1][i - 1], d[bit2]));
      }
    }
  }

  std::cout << dp[(1 << n) - 1][k] << std::endl;
  return 0;
}
