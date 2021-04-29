#include <iostream>
#include <vector>

struct point {
  double x, y;
  point(double x_, double y_) : x(x_), y(y_) { }
};

struct line {
  point a, b;
  line(point a_, point b_) : a(a_), b(b_) { }
};

double crossProduct(point a, point b, point c, point d) {
  return (b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y);
}

bool cross(line l, line chop) {
  double cp1 = crossProduct(l.a, l.b, l.a, chop.a);
  double cp2 = crossProduct(l.a, l.b, l.a, chop.b);
  double cp3 = crossProduct(chop.a, chop.b, chop.a, l.a);
  double cp4 = crossProduct(chop.a, chop.b, chop.a, l.b);  
  bool judge1 = cp1 * cp2 < 0;
  bool judge2 = cp3 * cp4 < 0;
  return judge1 && judge2;
}

int main() {
  double ax, ay, bx, by;
  std::cin >> ax >> ay >> bx >> by;
  point a(ax, ay), b(bx, by);
  line chop(a, b);

  int n;
  std::cin >> n;
  std::vector<point> vp;
  for (int i = 0; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    vp.push_back (point(x, y));
  }
  vp.push_back(vp[0]);

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    line l(vp[i], vp[i + 1]);
    if (cross(l, chop)) ++cnt;
  }

  std::cout << cnt / 2 + 1 << std::endl;
  return 0;
}
