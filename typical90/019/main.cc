#include <iostream>
#include <vector>
#include <cmath>

void chmin(int &a, int b) { a = std::min(a, b); }

int main() {
  constexpr int INF = 1 << 30;
  
  int n;
  std::cin >> n;
  n *= 2;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<std::vector<int> > dp(n, std::vector<int>(n, INF));
  for (int dist = 1; dist <= n - 1; dist += 2) {
    for (int left = 0; left < n - dist; ++left) {
      int right = left + dist;
      if (dist == 1) dp[left][right] = std::abs(a[left] - a[right]);
      else {
        for (int p = left + 1; p < right; p += 2) chmin(dp[left][right], dp[left][p] + dp[p + 1][right]);
        chmin(dp[left][right], dp[left + 1][right - 1] + std::abs(a[left] - a[right]));
      }
    }
  }

  std::cout << dp[0][n - 1] << std::endl;
  return 0;
}
