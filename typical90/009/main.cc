#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
  double x, y;
  Point(double x_, double y_) : x(x_), y(y_) { }
};

double angle(Point a, Point b) {
  double dx = b.x - a.x;
  double dy = b.y - a.y;
  double res = std::atan2(dy, dx) / M_PI * 180.0;
  if (res < 0.0) res += 360.0;
  return res;
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
    std::vector<double> va;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      va.push_back(angle(vp[i], vp[j]));
    }
    std::sort(va.begin(), va.end());
    for (int i = 0; i < n - 1; ++i) {
      double ag = va[i];
      double tg = ag + 180.0;
      if (tg > 360.0) tg -= 360.0;
      auto p = std::lower_bound(va.begin(), va.end(), tg);
      if (p != va.end()) {
        res = std::max(res, std::min(std::abs(ag - *p), 360.0 - std::abs(ag - *p)));
      }
      if (p != va.begin()) {
        --p;
        res = std::max(res, std::min(std::abs(ag - *p), 360.0 - std::abs(ag - *p)));
      }
    }
  }

  printf("%.10f\n", res);
  return 0;  
}
