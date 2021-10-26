#include <iostream>
#include <vector>

struct Point {
  long long x, y;
  Point(long long x_, long long y_) : x(x_), y(y_) { }
};

bool is_triangle(Point a, Point b, Point c) {
  long long dx1 = a.x - b.x, dx2 = b.x - c.x;
  long long dy1 = a.y - b.y, dy2 = b.y - c.y;
  return dx1 * dy2 != dx2 * dy1;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    long long x, y;
    std::cin >> x >> y;
    vp.push_back(Point(x, y));    
  }

  int res = 0;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (is_triangle(vp[i], vp[j], vp[k])) ++res;
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}
