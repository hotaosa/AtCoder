#include <iostream>
#include <vector>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<double, double>> vp;
  for (int i = 0; i < n; ++i) {
    double x, y;
    std::cin >> x >> y;
    vp.push_back(std::make_pair(x, y));
  }
  double res = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double dx = vp[i].first - vp[j].first;
      double dy = vp[i].second - vp[j].second;
      double dis = std::sqrt(dx * dx + dy * dy);
      res = std::max(res, dis);
    }
  }
  printf("%.5f\n", res);
  return 0;
}
