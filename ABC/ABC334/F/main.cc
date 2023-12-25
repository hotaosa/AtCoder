#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#include <atcoder/segtree>

constexpr double INF = 1e100;
double Operate(double a, double b) {
  return std::min(a, b);
}
double E() {
  return INF;
}
using Segtree = atcoder::segtree<double, Operate, E>;

struct Point {
  double x, y;
  Point (const double &x, const double &y) : x(x), y(y) { }
};

double Distance(const Point &a, const Point &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return std::sqrt(dx * dx + dy * dy);
}

int main() {
  std::cout << std::fixed << std::setprecision(15);
  int n, k;
  double sx, sy;
  std::cin >> n >> k >> sx >> sy;
  std::vector<Point> points = {{sx, sy}};
  for (int i = 0; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    points.emplace_back(x, y);
  }
  points.emplace_back(sx, sy);

  double sum = 0.0;
  std::vector<double> costs(n + 2, 0.0);
  for (int i = 1; i <= n + 1; ++i) {
    double d1 = Distance(points[i - 1], points[i]);
    double d2 = Distance(points[i - 1], points[0]) + Distance(points[0], points[i]);
    sum += d1;
    costs[i] = d2 - d1;
  }

  Segtree seg(n + 2);
  seg.set(0, sum);

  for (int i = 1; i <= n + 1; ++i) {
    int j = std::max(0, i - k);
    seg.set(i, seg.prod(j, i) + costs[i]);
  }

  std::cout << seg.get(n + 1) << std::endl;

  return 0;
}