#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  for (int dx = -2; dx <= 2; ++dx) {
    for (int dy = -2; dy <= 2; ++dy) {
      if (dx * dx + dy * dy != 5) continue;
      int x = x1 + dx, y = y1 + dy;
      if ((x - x2) * (x - x2) + (y - y2) * (y - y2) == 5) { cout << "Yes" << endl; return 0; }      
    }
  }
  cout << "No" << endl;
  return 0;
}
