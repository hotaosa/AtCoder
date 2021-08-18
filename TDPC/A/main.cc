#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1, 0);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> p[i];
    sum += p[i];
  }

  std::vector<std::vector<bool> > dp(n + 1, std::vector<bool>(sum + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      if (dp[i - 1][j]) {
        dp[i][j] = true;
        if (j + p[i] <= sum) dp[i][j + p[i]] = true;
      }
    }
  }

  int res = 0;
  for (int i = 0; i <= sum; ++i) if (dp[n][i]) ++res;
  std::cout << res << std::endl;
  return 0;
}
