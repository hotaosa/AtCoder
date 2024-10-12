#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point2d {
  double x;
  double y;
};

inline double Distance(Point2d p1, Point2d p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return std::sqrt(dx * dx + dy * dy);
}

int main() {
  std::size_t n;
  std::cin >> n;

  std::vector<Point2d> points(n + 2, {0.0, 0.0});
  for (std::size_t i = 1; i <= n; ++i) {
    std::cin >> points[i].x >> points[i].y;
  }

  double res = 0;
  for (std::size_t i = 1; i < std::size(points); ++i) {
    res += Distance(points[i], points[i - 1]);
  }

  std::cout << std::setprecision(10) << res << "\n";
  return 0;
}