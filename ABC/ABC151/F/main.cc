#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr double INF = 1.0e+30;

struct Point {
  double x, y;
  Point (double x_, double y_) : x(x_), y(y_) { }
};

bool is_linear(Point a, Point b, Point c) {
  double dx1 = a.x - b.x;
  double dx2 = b.x - c.x;
  double dy1 = a.y - b.y;
  double dy2 = b.y - c.y;
  return dy1 * dx2 == dy2 * dx1;  
}

double distance(Point a, Point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

Point center(Point a, Point b) {
  double x = (a.x + b.x) / 2;
  double y = (a.y + b.y) / 2;
  return Point(x, y);
}

Point center(Point a, Point b, Point c) {
  double alpha = a.x - b.x;
  double beta = a.y - b.y;
  double gamma = b.x - c.x;
  double delta = b.y - c.y;
  double d_a = distance(Point(0, 0), a);
  double d_b = distance(Point(0, 0), b);
  double d_c = distance(Point(0, 0), c);

  double coef = 1.0 / (2.0 * (alpha * delta - beta * gamma));
  double x = coef * (delta * (d_a * d_a - d_b * d_b) - beta * (d_b * d_b - d_c * d_c));
  double y = coef * (alpha * (d_b * d_b - d_c * d_c) - gamma * (d_a * d_a - d_b * d_b));
  return Point(x, y);
}

int main() {
  int n;
  cin >> n;
  vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    vp.emplace_back(x, y);
  }

  auto calc = [&](Point c) -> double {
    double ret = 0.0;
    for (int i = 0; i < n; ++i) ret = max(ret, distance(c, vp[i]));
    return ret;
  };

  double res = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Point c1 = center(vp[i], vp[j]);
      res = min(res, calc(c1));
      for (int k = j + 1; k < n; ++k) {
        if (!is_linear(vp[i], vp[j], vp[k])) {
          Point c2 = center(vp[i], vp[j], vp[k]);
          res = min(res, calc(c2));
        }
      }
    }
  }

  printf("%.10f\n", res);
  return 0;
}
