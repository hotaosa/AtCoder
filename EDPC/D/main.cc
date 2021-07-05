#include <iostream>
#include <vector>
#include <map>

void chmax(long long &a, long long b) { a = std::max(a, b); }

int main() {
  int n, w;
  std::cin >> n >> w;

  std::vector<int> weight(n + 1);
  std::vector<long long> value(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> weight[i] >> value[i];

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(w + 1, 0LL));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= w; ++j) {
      if (i < n) chmax(dp[i + 1][j], dp[i][j]);
      if (j < w) chmax(dp[i][j + 1], dp[i][j]);
      if (i < n && j + weight[i + 1] <= w) chmax(dp[i + 1][j + weight[i + 1]], dp[i][j] + value[i + 1]);
    }
  }

  std::cout << dp[n][w] << std::endl;
  return 0;
}
