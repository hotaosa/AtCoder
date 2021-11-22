#include <bits/stdc++.h>
#include <atcoder/all>

double cost(double x, const std::vector<double> &a) {
  double ret = 0.0;
  for (auto &p : a) ret += x + std::max(0.0, p - x * 2.0);
  return ret;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<double> a(n);
    for (auto &p : a) std::cin >> p;

    double l = 0.0, r = 1.0e9;
    while (r - l > 1.0e-7) {
      double c1 = l + (r - l) / 3.0;
      double c2 = r - (r - l) / 3.0;
      if (cost(c1, a) < cost(c2, a)) r = c2;
      else l = c1;
    }

    printf("%.8f\n", cost(l, a) / n);
    return 0;
}


