#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  long long x, y;
  Point(long long x, long long y) : x(x), y(y) { }
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
};

long long Cross(const Point &pa, const Point &pb) {
  return pa.x * pb.y - pa.y * pb.x;
}

long long AreaTwice(const Point &pa, const Point &pb, const Point &pc) {
  Point p1 = pb - pa;
  Point p2 = pc - pa;
  return abs(Cross(p1, p2));
}

int main() {
  int n;
  cin >> n;
  vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    vp.emplace_back(x, y);
  }

  long long s = 0;
  for (int i = 1; i < n - 1; ++i) s += AreaTwice(vp[0], vp[i], vp[i + 1]);

  long long res = 1LL << 62;
  long long cur = 0;
  int l = 0, r = 1;
  while (l < n) {
    while (cur <= s) {
      cur += AreaTwice(vp[l], vp[r], vp[(r + 1) % n]) * 4;
      res = min(res, abs(s - cur));
      r = (r + 1) % n;
    }
    while (l < n && cur >= s) {
      cur -= AreaTwice(vp[l], vp[(l + 1) % n], vp[r]) * 4;
      res = min(res, abs(s - cur));
      ++l;
    }
  }

  cout << res << endl;  
  return 0;
}