#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) std::cin >> l[i] >> r[i];

  std::vector<std::vector<double> > p(n, std::vector<double>(101, 0.0));
  for (int i = 0; i < n; ++i) {
    for (int j = l[i]; j <= r[i]; ++j) {
      p[i][j] = 1.0 / (r[i] - l[i] + 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= 100; ++j) p[i][j] += p[i][j - 1];
  }

  auto ex_inversion = [&](int i, int j) -> double {
    double d = 0.0;
    for (int k = 1; k <= 100; ++k) {
      double p1 = p[i][k] - p[i][k - 1];
      double p2 = p[j][k - 1];
      d += p1 * p2;
    }
    return d;
  };

  double res = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      res += ex_inversion(i, j);
    }
  }

  printf("%.10f\n", res);
  return 0;
}
