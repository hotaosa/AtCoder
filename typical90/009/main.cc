#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


struct Point {
  double px, py;
  Point(double x, double y) : px(x), py(y) { }
};

Point operator-(const Point &lhs, const Point &rhs) {
    return Point(lhs.px - rhs.px, lhs.py - rhs.py);
}

double getangle(Point p) {
  return (atan2(p.py, p.px) / M_PI + 1.0) * 180.0;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    vp.push_back(Point(x, y));
  }

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    std::vector<double> degs;
    for (int j = 0; j < n; ++j) if (j != i) degs.push_back(getangle(vp[i] - vp[j]));
    std::sort(degs.begin(), degs.end());

    for (double t1 : degs) {
      double terget = t1 + 180.0;
      if (terget > 360.0) terget -= 360.0;
      auto pt = std::lower_bound(degs.begin(), degs.end(), terget);
      if (pt != degs.end()) res = std::max(res, std::min(std::abs(t1 - *pt), 360.0 - std::abs(t1 - *pt)));
      if (pt != degs.begin()) {
        --pt;
        res = std::max(res, std::min(std::abs(t1 - *pt), 360.0 - std::abs(t1 - *pt)));
      }
    }
  }

  printf("%.10f\n", res);
  return 0;
}
