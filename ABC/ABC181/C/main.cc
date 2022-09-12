#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Point2d {
  int x, y;
  Point2d(const int &x, const int &y) : x(x), y(y) { }
};

bool OnALine(const Point2d &pa, const Point2d &pb, const Point2d &pc) {
  const int dx1 = pb.x - pa.x, dy1 = pb.y - pa.y;
  const int dx2 = pc.x - pb.x, dy2 = pc.y - pb.y;
  return dx1 * dy2 == dx2 * dy1;
}

int main() {
  int n;
  cin >> n;
  vector<Point2d> vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    vp.emplace_back(x, y);
  }

  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (OnALine(vp[i], vp[j], vp[k])) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;  
  return 0;
}
