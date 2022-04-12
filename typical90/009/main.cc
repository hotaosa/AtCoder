#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  double x, y;
  Point(double x_, double y_) : x(x_), y(y_) { }
};

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

double CalcAngle(Point a, Point b) {
  double ret = atan2(b.y - a.y, b.x - a.x);
  ret = (ret / M_PI + 1.0) * 180;
  return ret;
}

double CalcDiff(double a, double b) {
  double ret = abs(a - b);
  ret = min(ret, 360.0 - ret);
  return ret;
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

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    std::vector<double> rad;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      rad.push_back(CalcAngle(vp[i], vp[j]));
    }
    sort(rad.begin(), rad.end());
    for (double r : rad) {
      double target = r + 180.0;
      if (target > 360.0) target -= 360.0;
      auto p = lower_bound(rad.begin(), rad.end(), target);
      if (p == rad.end()) chmax(res, CalcDiff(r, rad[0]));
      else chmax(res, CalcDiff(r, *p));
      if (p == rad.begin()) chmax(res, CalcDiff(r, rad.back()));
      else chmax(res, CalcDiff(r, *(--p)));
    }
  }
  printf("%.10f\n", res);
  return 0;
}
