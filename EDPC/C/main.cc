#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > happiness(n, std::vector<int>(3));
  for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) std::cin >> happiness[i][j];

  std::vector<std::vector<int> > dp(n, std::vector<int>(3, 0));
  for (int i = 0; i < 3; ++i) dp[0][i] = happiness[0][i];
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (k == j) continue;
        dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + happiness[i][j]);
      }
    }
  }

  int res = std::max(dp[n - 1][0], std::max(dp[n - 1][1], dp[n - 1][2]));
  std::cout << res << std::endl;
  return 0;  
}
