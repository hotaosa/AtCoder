#include <iostream>
#include <vector>

int main() {
  constexpr long long MOD = 1000000007LL;
  int h, w;
  std::cin >> h >> w;

  if (h > 9 || w > 9) return 0;
  
  std::vector<std::vector<bool> > is_white(h, std::vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '.') is_white[i][j] = true;
  }

  std::vector<std::vector<long long> > dp(h + 1, std::vector<long long>(1 << w, 0LL));
  dp[0][0] = 1LL;

  auto possible = [&](int i, int j, int k) -> bool {
    std::vector<bool> putable(w, true);
    for (int l = 0; l < w; ++l) {
      if (j & (1 << l)) {
        for (int d = -1; d <= 1; ++d) if (l + d >= 0 && l + d < w) putable[l + d] = false;
      }
      if (k & (1 << l)) {
        if (l - 1 >= 0) putable[l - 1] = false;
        if (l + 1 < w) putable[l + 1] = false;
      }
    }
    for (int l = 0; l < w; ++l) {
      if (k & (1 << l)) {
        if (!is_white[i][l] || !putable[l]) return false;
      }
    }
    return true;      
  };

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < (1 << w); ++j) {
      if (dp[i][j] == 0LL) continue;
      for (int k = 0; k < (1 << w); ++k) {
        if (possible(i, j, k)) dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
      }
    }
  }

  long long res = 0LL;
  for (auto p : dp[h]) res = (res + p) % MOD;
  std::cout << res << std::endl;
  return 0;  
}
