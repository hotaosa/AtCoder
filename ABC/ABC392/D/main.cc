#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::unordered_map<int, double>> p(n);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    double pi = 1.0 / k;
    for (int j = 0; j < k; ++j) {
      int a;
      std::cin >> a;
      p[i][a] += pi;
    }
  }

  double res = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double sum = 0.0;
      for (auto [a, pi] : p[i]) {
        if (p[j].contains(a)) {
          sum += p[i][a] * p[j][a];
        }
      }
      res = std::max(res, sum);
    }
  }

  std::cout << std::setprecision(10) << res << "\n";
  return 0;
}