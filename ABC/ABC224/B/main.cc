#include <iostream>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int> > a(h, std::vector<int>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> a[i][j];

  bool is_ok = true;
  for (int i1 = 0; i1 < h - 1; ++i1) {
    for (int i2 = i1 + 1; i2 < h; ++i2) {
      for (int j1 = 0; j1 < w - 1; ++j1) {
        for (int j2 = j1 + 1; j2 < w; ++j2) {
          is_ok &= a[i1][j1] + a[i2][j2] <= a[i2][j1] + a[i1][j2];
        }
      }
    }
  }

  std::cout << (is_ok ? "Yes" : "No") << std::endl;
  return 0;
}
