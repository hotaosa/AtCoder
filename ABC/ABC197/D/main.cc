#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  double x, y;
  Point (double x_, double y_) : x(x_), y(y_) { }
};

Point rotate(Point pa, Point pc, double theta) {
  pa.x -= pc.x;
  pa.y -= pc.y;
  double x = pa.x * cos(theta) - pa.y * sin(theta) + pc.x;
  double y = pa.x * sin(theta) + pa.y * cos(theta) + pc.y;
  return Point(x, y);
}

int main() {
  int n;
  cin >> n;

  double x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  double xc = (x0 + x1) / 2.0;
  double yc = (y0 + y1) / 2.0;

  auto res = rotate(Point(x0, y0), Point(xc, yc), 2 * M_PI / (double)n);
  printf("%.10f %.10f\n", res.x, res.y);
  return 0;
}
