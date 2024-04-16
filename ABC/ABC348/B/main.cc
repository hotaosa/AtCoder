#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};

int SquareDist(Point a, Point b) {
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return dx * dx + dy * dy;
}

int main() {
  int n;
  cin >> n;
  vector<Point> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    vp.emplace_back(x, y);
  }

  for (int i = 0; i < n; ++i) {
    int dist = 0, farthest = -1;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      int d = SquareDist(vp[i], vp[j]);
      if (d > dist) {
        dist = d;
        farthest = j;
      }
    }
    cout << farthest + 1 << endl;
  }

  return 0;
}
