#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  double x, y;
  Point(double x, double y) : x(x), y(y) { }
};

double dist(Point a, Point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
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

  auto judge = [&](double r) -> bool {
    atcoder::dsu uf(n + 2);
    for (int i = 0; i < n; ++i) {
      if (100.0 - vp[i].y < 2 * r) uf.merge(i, n);
      if (vp[i].y + 100.0 < 2 * r) uf.merge(i, n + 1);
    }
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (dist(vp[i], vp[j]) < 2 * r) uf.merge(i, j);
      }
    }
    return !uf.same(n, n + 1);
  };

  double l = 0.0, r = 100.0;
  while (r - l > 1.0e-5) {
    double m = (l + r) / 2.0;
    if (judge(m)) l = m;
    else r = m;
  }

  printf("%.10f\n", l);  
  return 0;
}
