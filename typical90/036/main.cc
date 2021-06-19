#include <iostream>
#include <vector>

struct point {
  long long x;
  long long y;
  point(long long x_, long long y_) : x(x_), y(y_) { }
};

int main() {
  const long long INF = 1LL << 60;
  int n, q;
  std::cin >> n >> q;
  std::vector<point> p;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    std::cin >> x >> y;
    p.push_back(point(x - y, x + y));
  }

  long long xmin = INF, xmax = -INF, ymin = INF, ymax = -INF;
  for (int i = 0; i < n; ++i) {
    xmin = std::min(xmin, p[i].x);
    xmax = std::max(xmax, p[i].x);
    ymin = std::min(ymin, p[i].y);
    ymax = std::max(ymax, p[i].y);
  }

  for (int i = 0; i < q; ++i) {
    int qq;
    std::cin >> qq;
    --qq;
    long long res = 0LL;
    res = std::max(res, std::abs(p[qq].x - xmin));
    res = std::max(res, std::abs(p[qq].x - xmax));
    res = std::max(res, std::abs(p[qq].y - ymin));
    res = std::max(res, std::abs(p[qq].y - ymax));
    std::cout << res << std::endl;
  }
  return 0;    
}
