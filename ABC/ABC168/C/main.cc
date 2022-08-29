#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  double x, y;
  Point (double x_, double y_) : x(x_), y(y_) { }
};

double distance(Point a, Point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

Point rotate(Point pa, Point pc, double theta) {
  pa.x -= pc.x;
  pa.y -= pc.y;
  double x = pa.x * cos(theta) - pa.y * sin(theta) + pc.x;
  double y = pa.x * sin(theta) + pa.y * cos(theta) + pc.y;
  return Point(x, y);
}

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;

  Point ph0(0, a), pm0(0, b);
  Point center(0, 0);

  double theta_h = (h * 60 + m) / 720 * 2 * M_PI;
  double theta_m = m / 60 * 2 * M_PI;

  Point ph = rotate(ph0, center, theta_h);
  Point pm = rotate(pm0, center, theta_m);

  printf("%.10f\n", distance(ph, pm));  
  return 0;
}
