#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<double, double> > vp(n);
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    std::cin >> vp[i].first >> vp[i].second;
    sum += vp[i].first;
  }

  auto meet = [&](double d) -> bool {
    double d_l = 0.0, t_l = 0.0;
    for (int i = 0; i < n; ++i) {
      if (t_l + vp[i].first / vp[i].second <= d) {
        t_l += vp[i].first / vp[i].second;
        d_l += vp[i].first;
      } else {
        d_l += (d - t_l) * vp[i].second;
        break;
      }
    }
    double d_r = 0.0, t_r = 0.0;
    for (int i = n - 1; i >= 0; --i) {
      if (t_r + vp[i].first / vp[i].second <= d) {
        t_r += vp[i].first / vp[i].second;
        d_r += vp[i].first;
      } else {
        d_r += (d - t_r) * vp[i].second;
        break;
      }
    }
    return d_l + d_r >= sum;
  };

  double l = 0.0, r = 1.01e8;
  while (r - l > 1e-8) {
    double m = (l + r) / 2.0;
    if (meet(m)) r = m;
    else l = m;
  }

  double res = 0.0, tim = 0.0;
  for (int i = 0; i < n; ++i) {
    if (tim + vp[i].first / vp[i].second <= r) {
      tim += vp[i].first / vp[i].second;
      res += vp[i].first;
    } else {
      res += (r - tim) * vp[i].second;
      break;
    }
  }
  printf("%.10f\n", res);
  return 0;
}
