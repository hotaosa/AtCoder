#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  auto angle = [&](int id) -> double {
    double ret = 0.0;
    vector<double> v;
    for (int i = 0; i < n; ++i) {
      if (i == id) continue;
      double dx = x[i] - x[id];
      double dy = y[i] - y[id];
      v.push_back(atan2(dy, dx) + M_PI);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; ++i) {
      double target = v[i] + M_PI;
      if (target >= 2.0 * M_PI) target -= 2.0 * M_PI;
      auto p = lower_bound(v.begin(), v.end(), target);
      if (p != v.end()) {
        ret = max(ret, min(fabs(*p - v[i]), 2 * M_PI - fabs(*p - v[i])));
      }
      if (p != v.begin()) {
        --p;
        ret = max(ret, min(fabs(*p - v[i]), 2 * M_PI - fabs(*p - v[i])));
      }
    }
    return ret / M_PI * 180.0;
  };

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    res = max(res, angle(i));
  }
  printf("%.10f\n", res);
  
  return 0;
}
