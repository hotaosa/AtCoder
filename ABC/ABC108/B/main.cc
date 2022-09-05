#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) { }
};

Point rotate(Point p, Point c) {
  p.x -= c.x;
  p.y -= c.y;
  int x = p.y + c.x;
  int y = -p.x + c.y;
  return Point(x, y);
}

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  Point p1(x1, y1), p2(x2, y2);
  Point p3 = rotate(p1, p2);
  Point p4 = rotate(p2, p3);
  cout << p3.x << " " << p3.y << " " << p4.x << " " << p4.y << endl;
  return 0;
}
