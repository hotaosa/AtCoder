#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double t, l, x, y;
  cin >> t >> l >> x >> y;

  auto solve = [&](double k) -> double {
    double rad = k / t * M_PI * 2.0;
    double dx = -x;
    double dy = -l / 2.0 * sin(rad) - y;
    double dz = l / 2.0 * (1 - cos(rad));
    double dxy = sqrt(dx * dx + dy * dy);
    return 90.0 - atan2(dxy, dz) / M_PI * 180.0;
  };

  int q;
  cin >> q;
  while (q--) {
    double e;
    cin >> e;
    printf("%.10f\n", solve(e));
  }  
  return 0;
}
