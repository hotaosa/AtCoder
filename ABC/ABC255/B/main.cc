#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  vector<double> x(n), y(n);
  for (auto &p : a) { cin >> p; --p; }
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  auto calc_dist = [&](int i, int j) -> double {        
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
  };

  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    double min_dist = 1.0e+10;
    for (int j = 0; j < k; ++j) min_dist = min(min_dist, calc_dist(i, a[j]));
    res = max(res, min_dist);
  }
  printf("%.10f\n", res);
  return 0;
}
