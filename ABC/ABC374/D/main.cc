#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>

double Distance(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return std::sqrt(dx * dx + dy * dy);
}

int main() {
  int n;
  double s, t;
  std::cin >> n >> s >> t;

  std::vector<double> a(n), b(n), c(n), d(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  std::vector<double> draw_time(n);
  for (int i = 0; i < n; ++i) {
    draw_time[i] = Distance(a[i], b[i], c[i], d[i]) / t;
  }

  std::vector<int> order(n);
  std::iota(std::begin(order), std::end(order), 0);

  double res = 1.e+30;
  do {
    for (int bit = 0; bit < (1 << n); ++bit) {
      double x = 0.0, y = 0.0, cur = 0.0;
      for (int i : order) {
        if (bit >> i & 1) {
          cur += Distance(x, y, a[i], b[i]) / s + draw_time[i];
          x = c[i];
          y = d[i];
        } else {
          cur += Distance(x, y, c[i], d[i]) / s + draw_time[i];
          x = a[i];
          y = b[i];
        }
      }
      res = std::min(res, cur);
    }
  } while (std::next_permutation(std::begin(order), std::end(order)));

  std::cout << std::fixed << std::setprecision(8) << res << "\n";

  return 0;
}