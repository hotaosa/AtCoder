#include <iomanip>
#include <iostream>
#include <vector>
//
#include <Eigen/Core>

int main() {
  constexpr int SIZE = 100000;
  int n;
  std::cin >> n;
  std::vector p(n, std::vector<double>(SIZE, 0.0));
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    double pi = 1.0 / k;
    for (int j = 0; j < k; ++j) {
      int a;
      std::cin >> a;
      p[i][--a] += pi;
    }
  }

  double res = 0.0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Eigen::Map<Eigen::VectorXd> m1{p[i].data(), SIZE};
      Eigen::Map<Eigen::VectorXd> m2{p[j].data(), SIZE};
      res = std::max(res, m1.dot(m2));
    }
  }

  std::cout << std::setprecision(10) << res << "\n";
  return 0;
}