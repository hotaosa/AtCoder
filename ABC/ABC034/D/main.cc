#include <iostream>
#include <vector>
#include <algorithm>

struct water {
  const double TOL = 1e-8;
  
  double w, p;
  water(double w_, double p_) : w(w_), p(p_) { }
};

int main() {
  const double TOL = 1e-8;
  
  int n, k;
  std::cin >> n >> k;
  std::vector<water> vw;
  for (int i = 0; i < n; ++i) {
    double w, p;
    std::cin >> w >> p;
    vw.push_back(water(w, p * 0.01));
  }

  auto possible = [&](double m) -> bool {
    std::vector<double> diff;
    for (int i = 0; i < n; ++i) {
      double salt = vw[i].w * vw[i].p;
      double need = vw[i].w * m;
      diff.push_back(salt - need);
    }
    std::sort(diff.begin(), diff.end(), std::greater<double>());
    double d = 0.0;
    for (int i = 0; i < k; ++i) d += diff[i];
    return d >= 0.0;
  };

  double l = 0.0, r = 1.0;
  while (r - l > TOL) {
    double m = (l + r) / 2.;
    if (possible(m)) l = m;
    else r = m;
  }
  printf("%.10f\n", l * 100.0);  
  return 0;
}
