#include <iostream>

int main() {
  int n;
  double d, h;
  std::cin >> n >> d >> h;

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    double dd, hh;
    std::cin >> dd >> hh;
    double slope = (h - hh) / (d - dd);
    res = std::max(res, h - slope * d);
  }

  printf("%.5f\n", res);
  return 0;
}
