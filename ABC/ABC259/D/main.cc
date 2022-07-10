#include <iostream>
#include <cmath>
#include <atcoder/dsu>

using namespace std;

struct Circle {
  long long cx, cy, r;
  Circle(long long cx_, long long cy_, long long r_) : cx(cx_), cy(cy_), r(r_) { }
  bool OnTheLine(long long x, long long y) {
    double dx = cx - x, dy = cy - y;
    return dx * dx + dy * dy == r * r;
  }
  bool Intersect(Circle other) {
    long long r1 = r, r2 = other.r;
    long long dx = cx - other.cx, dy = cy - other.cy;
    if (dx * dx + dy * dy < r1 * r1 + r2 * r2 - 2 * r1 * r2) return false;
    if (dx * dx + dy * dy > r1 * r1 + r2 * r2 + 2 * r1 * r2) return false;
    return true;
  }
};

int main() {
  int n;
  long long sx, sy, tx, ty;
  cin >> n >> sx >> sy >> tx >> ty;
  vector<Circle> vc;
  for (int i = 0; i < n; ++i) {
    long long x, y, r;
    cin >> x >> y >> r;
    vc.emplace_back(x, y, r);
  }

  atcoder::dsu uf(n + 2);
  for (int i = 0; i < n; ++i) {
    if (vc[i].OnTheLine(sx, sy)) uf.merge(i, n);
    if (vc[i].OnTheLine(tx, ty)) uf.merge(i, n + 1);
    for (int j = i + 1; j < n; ++j) if (vc[i].Intersect(vc[j])) uf.merge(i, j);
  }

  cout << (uf.same(n, n + 1) ? "Yes" : "No") << endl;
  return 0;
}
