#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point {
  long long x, y;
  Point(long long x, long long y) : x(x), y(y) { }
  double dist() const { return sqrt(x * x + y * y); }
  double angle() const { return atan2(y, x); }
  bool operator<(const Point &other) const {
    return dist() < other.dist();
  }
  Point operator+=(const Point &other) {
    x += other.x;
    y += other.y;
    return *this;
  }
};

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    if (x || y) vp.emplace_back(x, y);
  }
  
  n = vp.size();  
  sort(vp.begin(), vp.end(), [](const auto &lhs, const auto &rhs) {
    return lhs.angle() < rhs.angle();
  });

  Point res(0, 0);
  for (int i = 0; i < n; ++i) {
    Point cur(0, 0);
    for (int j = 0; j < n; ++j) {
      cur += vp[(i + j) % n];
      chmax(res, cur);
    }
  }

  printf("%.10f\n", res.dist());
  return 0;
}
