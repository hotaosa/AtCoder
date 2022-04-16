#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  double t, l, x, y;
  int q;
  cin >> t >> l >> x >> y >> q;

  auto CalcPos = [&](int time) -> pair<double, double> {
    time %= (int)t;
    double rad = time / t * M_PI * 2.0;
    double pos_y = -l / 2.0 * sin(rad);
    double pos_z = -l / 2.0 * cos(rad) + l / 2.0;
    return make_pair(pos_y, pos_z);
  };

  while (q--) {
    int e;
    cin >> e;
    pair<double, double> pos_E8 = CalcPos(e);
    double dx = -x;
    double dy = pos_E8.first - y;
    double dz = pos_E8.second;
    double dxy = sqrt(dx * dx + dy * dy);
    double angle = atan2(dxy, dz);
    printf("%.10f\n", 90.0 - angle / M_PI * 180.0);
  }
  return 0;
}
