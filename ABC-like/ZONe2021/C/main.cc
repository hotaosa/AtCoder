#include <iostream>
#include <vector>

int calc(std::vector<int> p) {
  int res = 1 << 30;
  for (int i = 0; i < 5; ++i) res = std::min(res, p[i]);
  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> param(n, std::vector<int>(5));
  std::vector<int> ma(5, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      std::cin >> param[i][j];
      ma[j] = std::max(ma[j], param[i][j]);
    }
  }

  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      std::vector<int> p(5);
      for (int k = 0; k < 5; ++k) p[k] = std::max(param[i][k], param[j][k]);
      for (int k = 0; k < 5; ++k) {
        int tmp = p[k];
        p[k] = ma[k];
        res = std::max(res, calc(p));
        p[k] = tmp;
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}
