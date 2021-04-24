#include <iostream>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int>> a(h, std::vector<int>(w));
  std::vector<int> sum_r(h, 0), sum_c(w, 0);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> a[i][j];
      sum_r[i] += a[i][j];
      sum_c[j] += a[i][j];
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cout << sum_r[i] + sum_c[j] - a[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
