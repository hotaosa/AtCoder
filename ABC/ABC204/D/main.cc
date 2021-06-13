#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> t(n + 1, 0);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> t[i];
    sum += t[i];
  }

  int res = sum;
  std::vector<std::vector<bool> > dp(n + 1, std::vector<bool>(sum + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      if (dp[i - 1][j]) {
        dp[i][j] = true;
        dp[i][j + t[i]] = true;
        res = std::min(res, std::max(j + t[i], sum - j - t[i]));
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}
