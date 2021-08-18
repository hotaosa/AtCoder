#include <iostream>
#include <vector>

using v = std::vector<double>;
using vv = std::vector<v>;
using vvv = std::vector<vv>;
using vvvv = std::vector<vvv>;

int main() {
  int n;
  long long d;
  std::cin >> n >> d;

  std::vector<int> cnt(6, 0);
  while (d % 2 == 0) {
    ++cnt[2];
    d /= 2;
  }
  while (d % 3 == 0) {
    ++cnt[3];
    d /= 3;
  }
  while (d % 5 == 0) {
    ++cnt[5];
    d /= 5;
  }
  if (d > 1) { std::cout << "0" << std::endl; return 0; }

  vvvv dp(n + 1, vvv(60, vv(60, v(60, 0.0))));
  dp[0][0][0][0] = 1.0;

  std::vector<int> d2 = {0, 1, 0, 2, 0, 1};
  std::vector<int> d3 = {0, 0, 1, 0, 0, 1};
  std::vector<int> d5 = {0, 0, 0, 0, 1, 0};
  
  for (int i = 1; i <= n; ++i) {
    for (int c2 = 0; c2 <= cnt[2]; ++c2) {
      for (int c3 = 0; c3 <= cnt[3]; ++c3) {
        for (int c5 = 0; c5 <= cnt[5]; ++c5) {
          for (int dice = 0; dice < 6; ++dice) {
            int nc2 = std::min(cnt[2], c2 + d2[dice]);
            int nc3 = std::min(cnt[3], c3 + d3[dice]);
            int nc5 = std::min(cnt[5], c5 + d5[dice]);
            dp[i][nc2][nc3][nc5] += dp[i - 1][c2][c3][c5] / 6.0;
          }
        }
      }
    }
  }

  printf("%.10f\n", dp[n][cnt[2]][cnt[3]][cnt[5]]);
  return 0;
}
