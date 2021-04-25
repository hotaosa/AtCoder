#include <iostream>
#include <cmath>

int main() {
  double t, l, x, y;
  int q;
  std::cin >> t >> l >> x >> y >> q;

  for (int i = 0; i < q; ++i) {
    double e;
    std::cin >> e;
    double zz = l / 2.0 + l / 2.0 * (-1) * std::cos(e / t * 2.0 * M_PI);
    double yy = l / 2.0 * (-1) * std::sin(e / t * 2.0 * M_PI);
    double res = std::atan(zz / std::sqrt(x * x + (y - yy) * (y - yy))) / 2.0 / M_PI * 360.0;
    printf("%.10f\n", res);
  }
  return 0;
}
