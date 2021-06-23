#include <iostream>
#include <cmath>

int main() {
  const double TOL = 1.e-12;
  const double INF = 1.e+30;
  double a, b, c;
  std::cin >> a >> b >> c;
  double l = 0.0, r = INF;
  while (r - l > TOL) {
    double mid = (r + l) / 2.;
    if (a * mid + b * std::sin(c * mid * M_PI) >= 100.) r = mid;
    else l = mid;
  }
  printf("%.12f\n", l);
  return 0;
}
