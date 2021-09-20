#include <iostream>
#include <vector>

void chmin(int &a, int b) { a = std::min(a, b); }

int main() {
  constexpr int INF = 1 << 30;
  
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];

  std::vector<std::vector<std::vector<int> > > dp(n + 1, std::vector<std::vector<int> > (x + 1, std::vector<int>(y + 1, INF)));

  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= x; ++j) {
      for (int k = 0; k <= y; ++k) {
        if (dp[i][j][k] == INF) continue;
        chmin(dp[i + 1][j][k], dp[i][j][k]);
        chmin(dp[i + 1][std::min(x, j + a[i])][std::min(y, k + b[i])], dp[i][j][k] + 1);
      }
    }
  }

  std::cout << (dp[n][x][y] == INF ? -1 : dp[n][x][y]) << std::endl;
  return 0;
}
