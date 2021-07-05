#include <iostream>
#include <vector>

int main() {
  const int INF = 1 << 30;
  int n, k;
  std::cin >> n >> k;
  std::vector<int> h(n);
  for (int i = 0; i < n; ++i) std::cin >> h[i];
  std::vector<int> dp(n, INF);
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (i + j < n) {
        dp[i + j] = std::min(dp[i + j], dp[i] + std::abs(h[i] - h[i + j]));
      }
    }
  }
  std::cout << dp[n - 1] << std::endl;
  return 0;
}
