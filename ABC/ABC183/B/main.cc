#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  double dx = gx - sx, dy = gy + sy;
  printf("%.10f\n", sy * dx / dy + sx);
  return 0;
}
