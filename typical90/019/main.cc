#include <iostream>
#include <vector>

void chmin(int &a, int b) { a = std::min(a, b); }

int main() {
  const int INF = 1 << 30;
  int n;
  std::cin >> n;
  n *= 2;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<std::vector<int> > dp(n + 1, std::vector<int>(n + 1, INF));
  for (int i = 0; i <= n; ++i) dp[i][i] = 0;
  for (int i = 0; i < n; ++i) dp[i + 1][i] = 0;
  for (int i = 0; i < n - 1; ++i) dp[i][i + 1] = std::abs(a[i] - a[i + 1]);

  for (int dist = 1; dist < n; dist += 2) {
    for (int left = 0; left < n - dist; ++left) {
      int right = left + dist;
      for (int pa = left + 1; pa <= right; pa += 2) {
        chmin(dp[left][right], dp[left + 1][pa - 1] + dp[pa + 1][right] + std::abs(a[left] - a[pa]));
      }
    }
  }

  std::cout << dp[0][n - 1] << std::endl;
  return 0;  
}
