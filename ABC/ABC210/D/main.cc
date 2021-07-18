#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const long long INF = 1LL << 60;
  int h, w;
  long long c;
  std::cin >> h >> w >> c;
  std::vector<std::vector<long long> > a(h, std::vector<long long>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> a[i][j];

  long long res = INF;

  auto func = [&]() -> void {
    std::vector<std::vector<long long> > dp1(h, std::vector<long long>(w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        dp1[i][j] = a[i][j];
        if (j > 0) dp1[i][j] = std::min(dp1[i][j], dp1[i][j - 1] + c);
        if (i > 0) dp1[i][j] = std::min(dp1[i][j], dp1[i - 1][j] + c);
      }
    }
    std::vector<std::vector<long long> > dp2(h, std::vector<long long>(w, INF));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (i == 0 && j == 0) continue;
        if (j > 0) dp2[i][j] = std::min(dp2[i][j], dp1[i][j - 1] + c + a[i][j]);
        if (i > 0) dp2[i][j] = std::min(dp2[i][j], dp1[i - 1][j] + c + a[i][j]);
      }
    }
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) res = std::min(res, dp2[i][j]);
  };

  func();
  for (int i = 0; i < h; ++i) std::reverse(a[i].begin(), a[i].end());
  func();
  std::cout << res << std::endl;
  return 0;  
}
