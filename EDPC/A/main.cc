#include <iostream>
#include <vector>

int main() {
  const int INF = 1 << 30;
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (int i = 0; i < n; ++i) std::cin >> h[i];

  std::vector<int> dp(n, INF);
  dp[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    dp[i + 1] = std::min(dp[i + 1], dp[i] + std::abs(h[i] - h[i + 1]));
    if (i < n - 2) dp[i + 2] = std::min(dp[i + 2], dp[i] + std::abs(h[i] - h[i + 2]));
  }

  std::cout << dp[n - 1] << std::endl;
  return 0;
}
