#include <iostream>
#include <vector>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::vector<int> pa(a), pb(b);
  int sum = 0;
  for (int i = 0; i < a; ++i) { std::cin >> pa[i]; sum += pa[i]; }
  for (int i = 0; i < b; ++i) { std::cin >> pb[i]; sum += pb[i]; }

  std::vector<std::vector<int> > dp(a + 1, std::vector<int>(b + 1, 0));

  bool odd = ((a + b) & 1);
  for (int i = 1; i <= a; ++i) {
    if (odd == (i & 1)) dp[i][0] = dp[i - 1][0] + pa[a - i];
    else dp[i][0] = dp[i - 1][0] - pa[a - i];
  }
  for (int i = 1; i <= b; ++i) {
    if (odd == (i & 1)) dp[0][i] = dp[0][i - 1] + pb[b - i];
    else dp[0][i] = dp[0][i - 1] - pb[b - i];
  }

  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      if (odd == ((i + j) & 1)) dp[i][j] = std::max(dp[i - 1][j] + pa[a - i], dp[i][j - 1] + pb[b - j]);
      else dp[i][j] = std::min(dp[i - 1][j] - pa[a - i], dp[i][j - 1] - pb[b - j]);
    }
  }

  std::cout << (dp[a][b] + sum) / 2 << std::endl;
  return 0;  
}
