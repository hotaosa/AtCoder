#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point2d {
  int x, y;
  Point2d(const int &x, const int &y) : x(x), y(y) { }
};

struct Line2d {
Point2d pa, pb;
  Line2d(const Point2d &pa, const Point2d &pb) : pa(pa), pb(pb) { }
};

bool OnALine(const Point2d &pa, const Point2d &pb, const Point2d &pc) {
  const int dx1 = pb.x - pa.x, dy1 = pb.y - pa.y;
  const int dx2 = pc.x - pb.x, dy2 = pc.y - pb.y;
  return dx1 * dy2 == dx2 * dy1;
}

bool Intersect(const Line2d &la, const Line2d &lb) {
  const int s1 = (la.pb.x - la.pa.x) * (lb.pa.y - la.pa.y) - (lb.pa.x - la.pa.x) * (la.pb.y - la.pa.y);
  const int t1 = (la.pb.x - la.pa.x) * (lb.pb.y - la.pa.y) - (lb.pb.x - la.pa.x) * (la.pb.y - la.pa.y);
  const int s2 = (lb.pb.x - lb.pa.x) * (la.pa.y - lb.pa.y) - (la.pa.x - lb.pa.x) * (lb.pb.y - lb.pa.y);
  const int t2 = (lb.pb.x - lb.pa.x) * (la.pb.y - lb.pa.y) - (la.pb.x - lb.pa.x) * (lb.pb.y - lb.pa.y);
  return s1 * t1 < 0 && s2 * t2 < 0;
}

bool CanMakeConvexQuadrangle(const Point2d &pa, const Point2d &pb, const Point2d &pc, const Point2d &pd) {
  if (OnALine(pa, pb, pc)) return false;
  if (OnALine(pa, pb, pd)) return false;
  if (OnALine(pa, pc, pd)) return false;
  if (OnALine(pb, pc, pd)) return false;
  if (Intersect(Line2d(pa, pb), Line2d(pc, pd))) return true;
  if (Intersect(Line2d(pa, pc), Line2d(pb, pd))) return true;
  if (Intersect(Line2d(pa, pd), Line2d(pb, pc))) return true;
  return false;
}

int main() {
  vector<Point2d> points;
  for (int i = 0; i < 4; ++i) {
    int x, y;
    cin >> x >> y;
    points.emplace_back(x, y);
  }

  cout << (CanMakeConvexQuadrangle(points[0], points[1], points[2], points[3]) ? "Yes" : "No" ) << endl;
  return 0;
}
