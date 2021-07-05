#include <iostream>
#include <string>
#include <vector>

int main() {
  const long long MOD = 1000000007LL;
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<bool> > is_wall(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '#') is_wall[i][j] = true;
  }

  std::vector<std::vector<long long> > dp(h, std::vector<long long>(w, 0));
  dp[0][0] = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i < h - 1 && !is_wall[i + 1][j]) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
      if (j < w - 1 && !is_wall[i][j + 1]) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
    }
  }

  std::cout << dp[h - 1][w - 1] << std::endl;
  return 0;
}
